class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int r = -1;
        bool first = true;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                if (r != -1) {
                    continue;
                } else {
                    r = i;
                }
            } else {
                if (r != -1) {
                    if (!first) {
                        ans += ' ';
                    }
                    ans += s.substr(i + 1, r - i);
                    r = -1;
                    first = false;
                }
            }
        }
        if (r != -1) {
            if (!first) {
                ans += ' ';
            }
            ans += s.substr(0, r + 1);
        }
        return ans;
    }
};
