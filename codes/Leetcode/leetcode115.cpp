class Solution {
	public:
		int numDistinct(string s, string t) {
			int m = s.size(), n = t.size();
			int* dp = new int[m];
			for (int i = 0; i < m; i++) dp[i] = 0;

			int p = 1;
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < m; i++) {
					int tmp = s[i] == t[k] ? p : 0;
					p += dp[i];
					dp[i] = tmp;
				}
				p = 0;
			}
			int ans = 0;
			for (int i = 0; i < m; i++) ans += dp[i];
			delete[] dp;
			return ans;
		}
};
