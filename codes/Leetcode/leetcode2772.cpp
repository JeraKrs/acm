class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return true;
        }
        vector<int> delta;
        delta.resize(nums.size());
        int minus = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) minus -= delta[i-k];
            if (nums[i] < minus) return false;
            delta[i] = nums[i] - minus;
            if (i + k > nums.size() && delta[i]) return false;
            minus += delta[i];
        }
        return true;
    }
};
