class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int n = prices.size();
			if (n == 0) return 0;

			int* dp = new int[n];

			int mov = 0, bot = prices[0];
			for (int i = 0; i < n; i++) {
				dp[i] = mov;
				mov = max(mov, prices[i] - bot);
				bot = min(bot, prices[i]);
			}
			int ans = 0, top = prices[n-1];
			for (int i = n-2; i >= 0; i--) {
				ans = max(ans, dp[i] + top - prices[i]);
				top = max(top, prices[i]);
			}
			delete[] dp;
			return ans;
		}
};
