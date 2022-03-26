class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = 1;
        vector<int> ans;
        ans.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = s;
            s *= nums[i];
        }
        
        s = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= s;
            s *= nums[i];
        }
        return ans;
    }
};
