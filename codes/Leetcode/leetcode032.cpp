class Solution {
	public:
		int longestValidParentheses(string s) {
			int ans = 0;
			int* dp = new int[s.size() + 1];

			dp[0] = 0;
			for (int i = 1; i <= s.size(); i++) {
				dp[i] = 0;

				if (s[i-1] == ')') {
					int l = i - dp[i-1] - 1;
					if (l >= 0 && s[l-1] == '(') dp[i] = max(dp[i], dp[l-1] + dp[i-1] + 2);

					int r = i - 1;
					if (r >= 0 && s[r-1] == '(') dp[i] = max(dp[i], dp[i-2] + 2);
				}
				ans = max(ans, dp[i]);
			}

			delete dp;
			return ans;
		}
};
