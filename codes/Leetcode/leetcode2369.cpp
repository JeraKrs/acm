class Solution {
public:
    bool validPartition(vector<int>& nums) {
        std::vector<bool> dp;
        dp.resize(nums.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= nums.size(); ++i) {
            if (i >= 2 && nums[i-1] == nums[i-2]) {
                dp[i] = dp[i] || dp[i-2];
            }
            if (i >= 3) {
                if (nums[i-1] == nums[i-2] && nums[i-1] == nums[i-3]) {
                    dp[i] = dp[i] || dp[i-3];
                }
                if (nums[i-3] + 1 == nums[i-2] && nums[i-3] + 2 == nums[i-1]) {
                    dp[i] = dp[i] || dp[i-3];
                }
            }
        }
        return dp[nums.size()];
    }
};
