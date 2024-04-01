class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();

        std::vector<pair<int,int> > nums;
        for (int i = 0; i < n; ++i) {
            nums.emplace_back(make_pair(nums2[i], nums1[i]));
        }
        std::sort(nums.begin(), nums.end());

        std::vector<int> prefix;
        prefix.resize(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i-1] + nums[i-1].first;
        }

        std::vector<std::vector<int> > dp;
        dp.resize(n+1);
        for (int i = 0; i <= n; ++i) {
            dp[i].resize(n+1, 1e9);
            if (i) {
                dp[i][0] = dp[i-1][0] + nums[i-1].second;
            } else {
                dp[i][0] = 0;
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int unselected = dp[i-1][j] + nums[i-1].second + j * nums[i-1].first;
                int selected = dp[i-1][j-1] + prefix[i-1];
                dp[i][j] = std::min(unselected, selected);
            }
        }

        for (int i = 0; i <= n; ++i) {
            if (dp[n][i] <= x) {
                return i;
            }
        }
        return -1;
    }
};
