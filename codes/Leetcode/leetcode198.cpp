class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> steal;
        vector<int> no_steal;
        steal.resize(nums.size());
        no_steal.resize(nums.size());
        
        steal[0] = nums[0];
        no_steal[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            steal[i] = no_steal[i-1] + nums[i];
            no_steal[i] = max(steal[i-1], no_steal[i-1]);
        }
        return max(steal[nums.size() - 1], no_steal[nums.size() - 1]);
    }
};
