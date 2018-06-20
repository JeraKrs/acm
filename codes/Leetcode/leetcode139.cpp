class Solution {
	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			int n = s.size();
			bool* dp = new bool[n+1];
			for (int i = 0; i <= n; i++) dp[i] = false;
			dp[0] = true;

			for (int i = 0; i < n; i++) {
				if (dp[i] == false) continue;

				for (int j = 0; j < wordDict.size(); j++) {
					if (s.substr(i, wordDict[j].size()) == wordDict[j])
						dp[i + wordDict[j].size()] = true;
				}
			}

			bool ans = dp[n];
			delete[] dp;
			return ans;
		}
};
