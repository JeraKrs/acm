class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int l = 0, r = nums.size();
			while (l + 1 < r) {
				int mid = (l + r) >> 1;
				if (nums[mid] <= target) l = mid;
				else r = mid;
			}
			int ans = (l + r) >> 1;
			if (target <= nums[ans]) return ans;
			else return ans + 1;
		}
};
