class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			int m = obstacleGrid.size(), n = obstacleGrid[0].size();
			int* dp = new int[m*n];
			dp[0] = obstacleGrid[0][0] ? 0 : 1;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (i + j == 0) continue;
					dp[i*n+j] = 0;
					if (obstacleGrid[i][j]) continue;
					if (i) dp[i*n+j] += dp[(i-1)*n+j];
					if (j) dp[i*n+j] += dp[i*n+(j-1)];
				}
			}
			int ans = dp[m*n-1];
			delete[] dp;
			return ans;
		}
};
