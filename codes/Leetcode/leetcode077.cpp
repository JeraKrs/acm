class Solution {
	public:
		void dfs(int start, int end, int dep, vector<int> cur, vector<vector<int>>& ans) {
			if (dep == 0) {
				ans.push_back(cur);
				return;
			}

			for (int i = start; i <= end; i++) {
				vector<int> tmp = cur;
				tmp.push_back(i);
				dfs(i + 1, end, dep - 1, tmp, ans);
			}
		}

		vector<vector<int>> combine(int n, int k) {
			vector<vector<int>> ans;
			vector<int> cur;
			dfs(1, n, k, cur, ans);
			return ans;
		}
};
