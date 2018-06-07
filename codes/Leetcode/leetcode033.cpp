class Solution {
	public:
		int search(vector<int>& nums, int target) {
			if (nums.size() == 0) return -1;

			// find the index of maximum number
			int l = 0, r = nums.size(), mid;
			while (l + 1 < r) {
				mid = (l + r) / 2;
				if (nums[mid] >= nums[0]) l = mid;
				else r = mid;
			}
			mid = l + 1;

			int ans;
			if (target >= nums[0]) {
				ans = lower_bound(nums.begin(), nums.begin() + mid, target) - nums.begin();
			} else {
				ans = lower_bound(nums.begin() + mid, nums.end(), target) - nums.begin();
			}
			if (ans < nums.size() && nums[ans] == target) return ans;
			else return -1;
		}
};
