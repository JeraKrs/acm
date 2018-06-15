class Solution {
	public:
		void dfs(int start, int end, vector<int> cur, vector<vector<int>>& ans, vector<int>& nums) {
			ans.push_back(cur);
			for (int i = start; i < end; i++) {
				vector<int> tmp = cur;
				tmp.push_back(nums[i]);
				dfs(i + 1, end, tmp, ans, nums);
			}
		}

		vector<vector<int>> subsets(vector<int>& nums) {
			int n = nums.size();
			vector<vector<int>> ans;
			vector<int> cur;
			dfs(0, n, cur, ans, nums);
			return ans;
		}
};
