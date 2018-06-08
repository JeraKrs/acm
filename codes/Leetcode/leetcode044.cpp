class Solution {
	public:
		bool isMatch(string s, string p) {
			int ns = s.size(), np = p.size();
			bool** dp = new bool*[ns + 1];
			for (int i = 0; i <= ns; i++) {
				dp[i] = new bool[np + 1];
				for (int j = 0; j <= np; j++) dp[i][j] = false;
			}

			dp[0][0] = true;
			for (int i = 0; i <= ns; i++) {
				for (int j = 1; j <= np; j++) {
					if (i && (s[i-1] == p[j-1] || p[j-1] == '?' || p[j-1] == '*'))
						dp[i][j] |= dp[i-1][j-1];

					if (p[j-1] == '*') {
						if (i) dp[i][j] |= dp[i-1][j];
						dp[i][j] |= dp[i][j-1];
					}
				}
			}
			return dp[ns][np];
		}
};
