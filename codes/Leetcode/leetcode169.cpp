class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int c = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] & (1<<i)) {
                    ++c;
                }
            }
            if (c * 2 >= nums.size()) {
                ans |= (1<<i);
            }
        }
        return ans;
    }
};
