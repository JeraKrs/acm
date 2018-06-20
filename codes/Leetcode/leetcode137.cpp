class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			int n = nums.size();
			sort(nums.begin(), nums.end());
			for (int i = 0; i < n; i++) {
				if ((i == 0 || nums[i-1] != nums[i])
						&& (i == n-1 || nums[i+1] != nums[i]) )
					return nums[i];
			}
			return nums[0];
		}
};
