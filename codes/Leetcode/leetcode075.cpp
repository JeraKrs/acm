class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int r = 0, b = nums.size() - 1;

			for (int i = 0; i <= b; i++) {
				while (nums[i] != 1) {
					if (nums[i] == 2) {
						if (i > b) break;
						swap(nums[b--], nums[i]);
					}
					if (nums[i] == 0) {
						if (i < r) break;
						swap(nums[r++], nums[i]);
					}
				}
			}
		}
};
