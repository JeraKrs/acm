class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp;
        dp.resize(k+1);
        for (int i = 0; i <= k; ++i) {
            dp[i].resize(prices.size());
        }
        for (int i = 0; i < prices.size(); ++i) {
            dp[0][i] = 0;
        }
        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j < prices.size(); ++j) {
                dp[i][j] = dp[i][j-1];
                for (int t = 0; t < j; ++t) {
                    dp[i][j] = max(dp[i][j], dp[i-1][t] + prices[j] - prices[t]);
                }
                ans = max(dp[i][j], ans);
            }
        }
        return ans;
    }
};
