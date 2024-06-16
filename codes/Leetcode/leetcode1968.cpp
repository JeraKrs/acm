class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() - 1; i += 2) std::swap(nums[i], nums[i+1]);
        return nums;
    }
};

