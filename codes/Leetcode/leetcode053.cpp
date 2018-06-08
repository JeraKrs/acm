class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int n = nums.size();
			if (n == 0) return 0;

			int ans = nums[0], sum = 0;
			for (int i = 0; i < n; i++) {
				sum += nums[i];
				ans = max(ans, sum);
				if (sum < 0) sum = 0;
			}
			return ans;
		}
};
