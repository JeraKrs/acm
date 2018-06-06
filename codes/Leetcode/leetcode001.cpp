class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			int l = 0, r = nums.size() - 1;

			while (l < r) {
				while (nums[l] + nums[r] < target) l++;
				if (nums[l] + nums[r] == target) break;
				r--;
			}

			vector<int> ans;
			ans.push_back(l);
			ans.push_back(r);
			return ans;
		}
};
