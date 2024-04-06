class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        std::map<std::string, std::string> dict;
        for (int i = 0; i < knowledge.size(); ++i) {
            dict[knowledge[i][0]] = knowledge[i][1];
        }
        std::string ans, tmp;
        bool flag = false;
        for (int i = 0; i < s.size(); ++i) {
            if (flag) {
                if (s[i] == ')') {
                    flag = false;
                    if (dict.find(tmp) != dict.end()) {
                        ans += dict[tmp];
                    } else {
                        ans += "?";
                    }
                } else {
                    tmp += s[i];
                }
            } else if (s[i] == '(') {
                flag = true;
                tmp = "";
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};
