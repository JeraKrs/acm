class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int count = nums.size(), p = 1;
			for (int i = 1; i < nums.size(); i++) {
				if (nums[i-1] == nums[i]) count--;
				else nums[p++] = nums[i];
			}
			return count;
		}
};
