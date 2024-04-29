class Solution {
public:
    bool isPalindromeNum(int x) {
        std::vector<int> nums;
        while (x) {
            nums.emplace_back(x % 10);
            x /= 10;
        }
        for (int i = 0; i * 2 < nums.size(); ++i) {
            if (nums[i] != nums[nums.size() - i - 1]) return false;
        }
        return true;
    }
    int findNearestPalindromeNum(int x, int step) {
        int mov = 0;
        for (int i = 0; i <= 1e5; ++i) {
            if (isPalindromeNum(x + i * step)) return x + i * step;
        }
        return 0;
    }
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int mid = n&1 ? nums[n/2] : (nums[n/2-1] + nums[n/2]) / 2;
        int l = findNearestPalindromeNum(mid, -1);
        int r = findNearestPalindromeNum(mid, 1);

        long long ans_l = 0, ans_r = 0;
        for (auto i : nums) {
            ans_l += (i > l ? i - l : l - i);
            ans_r += (i > r ? i - r : r - i);
        }
        return std::min(ans_l, ans_r);
    }
};
