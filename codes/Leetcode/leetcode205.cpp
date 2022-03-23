class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int ms[255+5], mt[255+5];
        memset(ms, -1, sizeof(ms));
        memset(mt, -1, sizeof(mt));
        for (int i = 0; i < s.size(); ++i) {
            if (ms[s[i]] != -1 && ms[s[i]] != t[i]) {
                return false;
            } else {
                ms[s[i]] = t[i];
            }
            if (mt[t[i]] != -1 && mt[t[i]] != s[i]) {
                return false;
            } else {
                mt[t[i]] = s[i];
            }
        }
        return true;
    }
};
