class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0, n = nums.size();

        int p = 0;
        while (nums[p] > 0) {
            nums[p] *= -1;
            p = -nums[p];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
            }
        }
        return p;
    }
};
