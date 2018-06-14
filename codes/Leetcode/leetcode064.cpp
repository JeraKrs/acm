class Solution {
	public:
		int minPathSum(vector<vector<int>>& grid) {
			int m = grid.size(), n = grid[0].size();
			int* dp = new int[m*n];
			dp[0] = grid[0][0];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (i + j == 0) continue;
					int k = i * n + j;
					dp[k] = -1;
					if (i) {
						int tmp = dp[(i-1)*n+j] + grid[i][j];
						dp[k] = dp[k] == -1 ? tmp : min(dp[k], tmp);
					}
					if (j) {
						int tmp = dp[i*n+(j-1)] + grid[i][j];
						dp[k] = dp[k] == -1 ? tmp : min(dp[k], tmp);
					}
				}
			}
			int ans = dp[m*n-1];
			delete dp;
			return ans;
		}
};
