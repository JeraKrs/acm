class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int mov = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (mov < i && sum - nums[mov] >= target) {
                sum -= nums[mov++];
            }
            if (sum < target) {
                continue;
            }

            if (ans) {
                ans = min(ans, i - mov + 1);
            } else {
                ans = i - mov + 1;
            }
        }
        return ans;
    }
};
