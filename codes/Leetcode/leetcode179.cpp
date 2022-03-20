class Solution {
public:
    static bool cmp(const int& lhs, const int& rhs) {
        string lhv = to_string(lhs) + to_string(rhs);
        string rhv = to_string(rhs) + to_string(lhs);
        return lhv > rhv;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Solution::cmp);
        string ans;
        if (nums[0] == 0) {
            ans = "0";
            return ans;
        }
        for (int i = 0; i < nums.size(); ++i) {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};
