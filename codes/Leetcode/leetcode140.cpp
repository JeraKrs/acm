class Solution {
	public:
		bool dfs(int d, string s, string t, vector<string>& wordDict, vector<string>& ans, bool* dp) {
			if (d >= s.size()) {
				ans.push_back(t);
				return true;
			}
			bool ret = false;

			for (int i = 0; i < wordDict.size(); i++) {
				int n = wordDict[i].size();
				if (s.substr(d, n) == wordDict[i] && dp[d+n]) {

					string tmp = t + (t == "" ? wordDict[i] : " " + wordDict[i]);
					if (dfs(d + n, s, tmp, wordDict, ans, dp)) ret = true;
					else dp[d+n] = false;
				}
			}
			return ret;
		}

		vector<string> wordBreak(string s, vector<string>& wordDict) {
			vector<string> ans;

			int m = s.size();
			bool* dp = new bool[m+1];
			for (int i = 0; i <= m; i++) dp[i] = true;

			dfs(0, s, "", wordDict, ans, dp);

			delete[] dp;
			return ans;
		}
};
