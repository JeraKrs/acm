class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        int max_value = *max_element(nums.begin(), nums.end());
        int exp = 1;
        vector<int> buf(n);

        while (max_value >= exp) {
            vector<int> cnt(10);
            for (int i = 0; i < n; ++i) {
                int d = (nums[i] / exp) % 10;
                cnt[d]++;
            }
            for (int i = 1; i < 10; ++i) {
                cnt[i] += cnt[i-1];
            }

            for (int i = n-1; i >= 0; i--) {
                int d = (nums[i] / exp) % 10;
                buf[--cnt[d]] = nums[i];
            }

            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, nums[i] - nums[i-1]);
        }
        return ans;
    }
};
