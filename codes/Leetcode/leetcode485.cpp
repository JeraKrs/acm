class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        for (auto i : nums) {
            if (!i) {
                cnt = 0;
                continue;
            }
            ++cnt;
            ans = std::max(ans, cnt);
        }
        return ans;
    }
};
