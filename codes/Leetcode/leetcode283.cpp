class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                nums[p++] = nums[i];
            }
        }
        for (int i = p; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};
