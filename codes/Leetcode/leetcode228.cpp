class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int p = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (i < nums.size() && nums[i-1] + 1 == nums[i]) {
                continue;
            }
            string s = to_string(nums[p]);
            if (i - 1 != p) {
                s += "->";
                s += to_string(nums[i-1]);
            }
            ans.emplace_back(s);
            p = i;
        }
        return ans;
    }
};
