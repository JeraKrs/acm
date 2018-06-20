class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {
			int ans = 1, n = nums.size();
			if (n == 0) return 0;

			sort(nums.begin(), nums.end());

			int* dp = new int[n];
			dp[0] = 1;
			for (int i = 1; i < n; i++) {
				if (nums[i-1] + 1 == nums[i]) dp[i] = dp[i-1] + 1;
				else if (nums[i-1] == nums[i]) dp[i] = dp[i-1];
				else dp[i] = 1;
				ans = max(ans, dp[i]);
			}
			return ans;
		}
};
