class Solution {
	public:
		void dfs(int d, int p, string s, string c, vector<string>& ans) {
			if (d == 4) {
				if (p == s.size()) ans.push_back(c.substr(0, c.size()-1));
				return;
			}

			int n = s[p] - '0';
			c = c + s[p++];
			dfs(d + 1, p, s, c + ".", ans);

			if (n == 0) return;

			while (p < s.size()) {
				n = n * 10 + s[p] - '0';
				if (n >= 0 && n <= 255) {
					c = c + s[p++];
					dfs(d + 1, p, s, c + ".", ans);
				} else break;
			}
		}

		vector<string> restoreIpAddresses(string s) {
			vector<string> ans;
			dfs(0, 0, s, "", ans);
			return ans;
		}
};
