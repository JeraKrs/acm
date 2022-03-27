class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        for (int i = 0; i + 1 < nums.size(); ++i) {
            while (nums[i] != i && nums[i] != -1) {
                int pos = nums[i];
                nums[i] = nums[pos];
                nums[pos] = pos;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -1) {
                return i;
            }
        }
        return -1;
    }
};
