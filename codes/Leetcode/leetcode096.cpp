class Solution {
	public:
		int numTrees(int n) {
			if (n == 0) return 0;

			int* dp = new int[n+1];
			dp[0] = 1;
			for (int i = 1; i <= n; i++) {
				dp[i] = 0;
				for (int j = 1; j <= i; j++)
					dp[i] += dp[j-1] * dp[i-j];
			}

			int ans = dp[n];
			delete[] dp;
			return ans;
		}
};
