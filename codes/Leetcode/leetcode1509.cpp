class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;

        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n-1] - nums[0];
        for (int i = 0; i <= 3; ++i) {
            ans = std::min(ans, nums[n-4+i] - nums[i]);
        }
        return ans;
    }
};
