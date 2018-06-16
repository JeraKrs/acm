class Solution {
	public:
		void dfs(int d, vector<int>& nums, vector<int> cur, vector<vector<int>>& ans) {
			if (d >= nums.size()) {
				ans.push_back(cur);
				return;
			}

			int n = 1;
			while (d + n < nums.size() && nums[d] == nums[d+n]) n++;

			dfs(d + n, nums, cur, ans);
			for (int i = 1; i <= n; i++) {
				cur.push_back(nums[d]);
				dfs(d + n, nums, cur, ans);
			}
		}

		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int>> ans;
			vector<int> cur;
			sort(nums.begin(), nums.end());
			dfs(0, nums, cur, ans);
			return ans;
		}
};
