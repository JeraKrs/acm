class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int mov = 0, n = nums.size();
			for (int i = 0; i < n;) {
				int p = i;
				while (p < n && nums[i] == nums[p]) p++;
				for (int j = 0; j < min(2, p - i); j++)
					nums[mov++] = nums[i];
				i = p;
			}
			return mov;
		}
};
