class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if(strs.empty()) return "";
			int n = strs.size(), ans = strs[0].size();

			for (int i = 1; i < n; i++) {
				int t = strs[i].size();
				ans = min(t, ans);
				for (int j = 0; j < ans; j++) {
					if (strs[0][j] != strs[i][j]) ans = j;
				}
			}
			return strs[0].substr(0, ans);
		}
};
