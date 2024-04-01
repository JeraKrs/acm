class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        std::vector<int> zeros;
        zeros.resize(nums.size() + 1, -1);

        int p = 0;
        int ans = 0;

        zeros[0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            p += (nums[i-1] == 0 ? 1 : 0);
            if (zeros[p] == -1) zeros[p] = i;
            ans = std::max(ans, i - zeros[std::max(0, p-k)]);
        }
        return ans;
    }
};
