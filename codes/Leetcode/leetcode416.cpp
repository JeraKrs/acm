class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum&1) return false;

        std::vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (auto i : nums) {
            for (int j = sum - i; j >= 0; j--) {
                if (dp[j]) dp[i+j] = true;
            }
        }
        
        return dp[sum>>1];

    }
};
