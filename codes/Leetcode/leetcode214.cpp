class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() == 0) {
            return s;
        }
        vector<int> jump;
        jump.resize(s.size()+1);
        int p = jump[1] = 0;
        for (int i = 2; i <= s.size(); ++i) {
            while (p && s[p] != s[i-1]) {
                p = jump[p];
            }

            if (s[p] == s[i-1]) {
                ++p;
            }
            jump[i] = p;
        }

        string t = s;
        reverse(t.begin(), t.end());
        p = 0;
        for (int i = 0; i < t.size(); ++i) {
            while (p && s[p] != t[i]) {
                p = jump[p];
            }
            if (s[p] == t[i]) {
                ++p;
            }
        }
        string ans = t.substr(0, t.size() - p) + s;
        return ans;
    }
};
