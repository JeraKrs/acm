class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			int n = strs.size();
			vector<pair<string, int>> hashs;
			vector<vector<string>> res;

			if (n == 0) return res;

			for (int i = 0; i < n; i++) {
				string tmp = strs[i];
				sort(tmp.begin(), tmp.end());
				hashs.push_back(make_pair(tmp, i));
			}
			sort(hashs.begin(), hashs.end());

			int k = 0;
			vector<string> ans;
			for (int i = 0; i < n; i++) {
				if (hashs[i].first != hashs[k].first) {
					k = i;
					res.push_back(ans);
					ans.clear();
				}
				ans.push_back(strs[hashs[i].second]);
			}
			res.push_back(ans);

			return res;
		}
};
