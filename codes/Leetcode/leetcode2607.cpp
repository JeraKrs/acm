class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();

        std::vector<bool> flags;
        flags.resize(n, false);

        long long ans = 0;
        for (int i = 0; i < std::min(k, n); ++i) {
            int t = i;
            std::vector<int> nums;

            while (!flags[t]) {
                nums.emplace_back(arr[t]);
                flags[t] = true;
                t = (t + k) % n;
            }
            if (nums.size() == 0) break;
            std::sort(nums.begin(), nums.end());
            int standard = nums[nums.size() / 2];
            for (int j = 0; j < nums.size(); ++j) {
                ans += (nums[j] > standard ? nums[j] - standard : standard - nums[j]);
            }
        }
        return ans;
    }
};
