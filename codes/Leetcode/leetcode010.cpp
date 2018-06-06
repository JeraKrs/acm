class Solution {
	public:
		bool isMatch(string s, string p) {
			int ns = s.size();
			int np = p.size();

			int* flag = new int[np];
			memset(flag, 0, sizeof(flag));

			string t;
			for (int i = 0; i < np; i++) {
				if (p[i] != '*') t += p[i];
				else flag[t.size()-1] = 1;
			}

			int nt = t.size();

			int** dp = new int*[ns+1];
			for (int i = 0; i <= ns; i++)
				dp[i] = new int[nt+1];
			dp[0][0] = 1;

			for (int i = 0; i <= ns; i++) {
				for (int j = 1; j <= nt; j++) {
					dp[i][j] = 0;
					if (i && (s[i-1] == t[j-1] || t[j-1] == '.'))
						dp[i][j] |= dp[i-1][j-1];

					if (flag[j-1]) {
						dp[i][j] |= dp[i][j-1];
						if (i && (s[i-1] == t[j-1] || t[j-1] == '.'))
							dp[i][j] |= dp[i-1][j];
					}
				}
			}
			return dp[ns][nt] == 1;
		}
};
