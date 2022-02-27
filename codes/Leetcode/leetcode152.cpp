class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int ans = 0;
        int pos_result = 0;
        int neg_result = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                pos_result = 0;
                neg_result = 0;
            } else if (nums[i] > 0) {
                pos_result *= nums[i];
                neg_result *= nums[i];
                if (pos_result == 0) {
                    pos_result = nums[i];
                }
            } else {
                int tmp = pos_result;
                pos_result = neg_result * nums[i];
                neg_result = tmp * nums[i];
                if (neg_result == 0) {
                    neg_result = nums[i];
                }
            }

            ans = max(ans, pos_result);
        }
        return ans;
    }
};
