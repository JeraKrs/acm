class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int m = 1<<n;
        std::vector<std::vector<int> > dp;
        dp.resize(m);
        for (int i = 0; i < m; ++i) {
            dp[i].resize(n, 0);
        }
        for (int i = 0; i < n; ++i) {
            int s = 1<<i;
            dp[s][i] = 1;
        }
        printf("m=%d\n", m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;
                if (i & (1<<j) == 0) continue;
                for (int k = 0; k < n; ++k) {
                    int s = (i | (1<<k));
                    if (s == i) continue;
                    if (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0) {
                        dp[s][k] = (dp[s][k] + dp[i][j]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + dp[m-1][i]) % mod;
        }
        return ans;
    }
};
