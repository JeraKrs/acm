class Solution {
	public:
		int minDistance(string word1, string word2) {
			int m = word1.size(), n = word2.size();
			int** dp = new int*[m+1];
			for (int i = 0; i <= m; i++) dp[i] = new int[n+1];

			for (int i = 0; i <= m; i++) {
				for (int j = 0; j <= n; j++) dp[i][j] = max(m, n);
			}
			dp[0][0] = 0;

			for (int i = 0; i <= m; i++) {
				for (int j = 0; j <= n; j++) {
					if (i < m && j < n) {
						if (word1[i] == word2[j])
							dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
						else
							// Replace
							dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 1);
					}

					// Insert
					if (i < m)
						dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);

					// Remove
					if (j < n)
						dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
				}
			}

			int ans = dp[m][n];
			for (int i = 0; i <= m; i++) delete dp[i];
			delete dp;
			return ans;
		}
};
