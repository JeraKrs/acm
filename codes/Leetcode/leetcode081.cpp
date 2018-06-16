class Solution {
	public:
		bool search(vector<int>& nums, int target) {
			if (nums.size() == 0) return false;

			int l = 0, r = nums.size()-1, mid;
			while (l + 1 < r) {
				mid = (l + r) / 2;
				if (nums[mid] > nums[0]) l = mid;
				else if (nums[mid] < nums[0]) r = mid;
				else {
					if (nums[r] == nums[0]) r--;
					else l++;
				}
			}
			mid = l + 1;

			int ans;
			if (target >= nums[0]) {
				ans = lower_bound(nums.begin(), nums.begin() + mid, target) - nums.begin();
			} else {
				ans = lower_bound(nums.begin() + mid, nums.end(), target) - nums.begin();
			}
			if (ans < nums.size() && nums[ans] == target) return true;
			else return false;
		}
};
