class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			if (prices.size() == 0) return 0;

			int ans = 0, bot = prices[0];
			for (int i = 1; i < prices.size(); i++) {
				ans = max(ans, prices[i] - bot);
				bot = min(bot, prices[i]);
			}
			return ans;
		}
};
