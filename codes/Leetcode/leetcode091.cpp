class Solution {
	public:
		int numDecodings(string s) {
			int n = s.size();
			int* dp = new int[n+1];
			dp[0] = 1;
			for (int i = 1; i <= n; i++) {
				dp[i] = (s[i-1] == '0' ? 0 : dp[i-1]);

				if (i >= 2) {
					int k = (s[i-2] - '0') * 10 + s[i-1] - '0';
					if (s[i-2] != '0' && k > 0 && k <= 26)
						dp[i] += dp[i-2];
				}
			}
			int ans = dp[n];
			delete[] dp;
			return ans;
		}
};
