class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> steal;
        vector<int> no_steal;
        steal.resize(nums.size());
        no_steal.resize(nums.size());

        int ans = nums[0];
        steal[0] = nums[0];
        no_steal[0] = 0;
        for (int i = 1; i + 1 < nums.size(); ++i) {
            steal[i] = no_steal[i-1] + nums[i];
            no_steal[i] = max(no_steal[i-1], steal[i-1]);
            ans = max(ans, max(steal[i], no_steal[i]));
        }

        steal[0] = 0;
        no_steal[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            steal[i] = no_steal[i-1] + nums[i];
            no_steal[i] = max(no_steal[i-1], steal[i-1]);
            ans = max(ans, max(steal[i], no_steal[i]));
        }
        return ans;
    }
};
