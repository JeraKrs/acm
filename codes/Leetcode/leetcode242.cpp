class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i])
                return false;
        }
        return true;
    }
};
