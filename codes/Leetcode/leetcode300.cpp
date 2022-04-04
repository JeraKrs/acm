class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size());
        int ans = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int mv = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    mv = max(mv, dp[j]);
                }
            }
            dp[i] = mv + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
