class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        std::vector<int> dp;
        std::set<int> fives;
        int f = 1;
        for (int i = 0; f < 1<<16; ++i) {
            fives.insert(f);
            f *= 5;
        }

        dp.resize(s.size() + 1, s.size()+1);
        dp[0] = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') continue;
            int v = 0;
            for (int j = i; j < s.size(); ++j) {
                v = v*2 + (s[j] - '0');
                if (fives.find(v) != fives.end()) {
                    dp[j+1] = min(dp[j+1], dp[i] + 1);
                }
            }
        }
        return dp[s.size()] == s.size() + 1 ? -1 : dp[s.size()];
    }
};
