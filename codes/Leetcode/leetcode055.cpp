class Solution {
	public:
		bool canJump(vector<int>& nums) {
			int p = 0, n = nums.size();
			for (int i = 0; i < n; i++) {
				if (i <= p) p = max(p, i + nums[i]);
				else return false;
			}
			return true;
		}
};
