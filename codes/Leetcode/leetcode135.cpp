class Solution {
	public:
		int candy(vector<int>& ratings) {
			int n = ratings.size();
			int* dp = new int[n];
			for (int i = 0; i < n; i++) dp[i] = 0;

			queue<int> que;
			for (int i = 0; i < n; i++) {
				if ((i == 0 || ratings[i-1] >= ratings[i])
						&& (i == n-1 || ratings[i+1] >= ratings[i]) ) {
					dp[i] = 1;
					que.push(i);
				}
			}

			while (!que.empty()) {
				int u = que.front();
				que.pop();

				if (u && ratings[u-1] > ratings[u] && dp[u-1] < dp[u]+1) {
					dp[u-1] = dp[u] + 1;
					que.push(u-1);
				}
				if (u + 1 < n && ratings[u+1] > ratings[u] && dp[u+1] < dp[u] + 1) {
					dp[u+1] = dp[u] + 1;
					que.push(u+1);
				}
			}

			int ans = 0;
			for (int i = 0; i < n; i++) ans += dp[i];
			delete[] dp;
			return ans;
		}
};
