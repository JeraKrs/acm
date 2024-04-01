class Solution {
public:
    string removeDuplicateLetters(string s) {
        queue<int> pos[26];
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i]- 'a'].push(i);
        }
        vector<int> is_remove;
        is_remove.resize(s.size());
        int stub = -1;
        for (int i = 0; i < s.size(); ++i) {
            is_remove[i] = true;
            int c = s[i] - 'a';

            if (pos[c].front() < i) continue;

            for (int k = 25; k > c; --k) {
                while (pos[k].size() > 1
                    && pos[k].front() < i
                    && pos[k].front() > stub) {
                        pos[k].pop();
                }
                if (pos[k].size() && pos[k].front() < i) {
                    stub = max(stub, pos[k].front());
                }
            }
            if (pos[c].size() == 1) {
                stub = i;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (pos[i].empty()) continue;
            is_remove[pos[i].front()] = false;
        }


        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (is_remove[i]) continue;
            ans += s[i];
        }
        return ans;
    }
};
