class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int chance = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                if (chance == 0) return false;
                if (i == 1 || nums[i] >= nums[i-2]) {
                    chance--;
                } else if (i == nums.size()-1 || nums[i-1] <= nums[i+1]) {
                    chance--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
