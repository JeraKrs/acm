class Solution {
public:
    int maxSum(vector<int>& nums) {
        std::vector<int> bits;
        bits.resize(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int t = nums[i];
            bits[i] = 0;
            while (t) {
                bits[i] = std::max(bits[i], t % 10);
                t /= 10;
            }
        }
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (bits[i] == bits[j]) {
                    ans = std::max(ans, nums[i] + nums[j]);
                }
            }
        }
        return ans;
    }
};
