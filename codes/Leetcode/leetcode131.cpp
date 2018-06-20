class Solution {
	public:
		bool isPalindrome(string s) {
			int n = s.size();
			for (int i = 0; i + i < n; i++)
				if (s[i] != s[n-i-1]) return false;
			return true;
		}

		void dfs(int d, string &s, vector<string> cur, vector<vector<string>>& ans) {
			if (d >= s.size()) {
				ans.push_back(cur);
				return;
			}

			for (int i = d; i < s.size(); i++) {

				string t = s.substr(d, i-d+1);
				if (isPalindrome(t)) {
					vector<string> tmp = cur;
					tmp.push_back(t);
					dfs(i+1, s, tmp, ans);
				}
			}
		}
		vector<vector<string>> partition(string s) {
			vector<vector<string>> ans;
			vector<string> cur;
			dfs(0, s, cur, ans);
			return ans;
		}
};
