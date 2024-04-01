class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        std::vector<int> seen;
        std::vector<int> ans;
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != -1) {
                seen.push_back(nums[i]);
                p = 0;
            } else if (p + 1 <= seen.size()) {
                ans.push_back(seen[seen.size() - p - 1]);
                p++;
            } else {
                ans.push_back(-1);
                p++;
            }
        }
        return ans;
    }
};
