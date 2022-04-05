class Solution {
public:
    int removeInvalidParenthesesCounter(const string& s) {
        int cnt = 0, sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++cnt;
            } else if (s[i] == ')') {
                if (cnt) {
                    --cnt;
                } else {
                    ++sum;
                }
            }
        }
        return sum + cnt;
    }
    void dfs(int pos, int dep, int cnt, const string& s, char tmp[], set<string>& res) {
        if (pos == s.size()) {
            if (cnt == 0) {
                tmp[dep] = '\0';
                string cur = tmp;
                if (removeInvalidParenthesesCounter(cur) == 0) {
                    res.insert(cur);
                }
            }
            return;
        }
        if (s.size() - pos > cnt) {
            dfs(pos + 1, dep, cnt, s, tmp, res);
        }

        if (cnt) {
            tmp[dep] = s[pos];
            dfs(pos + 1, dep + 1, cnt - 1, s, tmp, res);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> res;   
        int need_remove = removeInvalidParenthesesCounter(s);
        char tmp[s.size()+1];

        dfs(0, 0, s.size() - need_remove, s, tmp, res);

        vector<string> ans;
        for (auto iter = res.begin(); iter != res.end(); iter++) {
            ans.push_back(*iter);
        }
        return ans;
    }
};
