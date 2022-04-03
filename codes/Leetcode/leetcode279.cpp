class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;
        dp.resize(n+1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = n;
        }
        dp[0] = 0;

        for (int i = 1; i * i <= n; ++i) {
            int s = i * i;
            for (int j = s; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j-s] + 1);
            }
        }

        return dp[n];
    }
};
