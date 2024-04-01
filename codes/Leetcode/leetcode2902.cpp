class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const int mod = 1e9 + 7;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        std::sort(nums.begin(), nums.end());
        std::vector<pair<int, int> > packages;
        packages.push_back(make_pair(nums[0], 1));
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                packages[packages.size()-1].second++;
            } else {
                packages.push_back(make_pair(nums[i], 1));
            }
        }

        int n = packages.size();
        long long dp[n+1][sum+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int zero = 0;
        long g[sum+1];
        for (int i = 1; i <= n; ++i) {
            if (packages[i-1].first == 0) {
                zero = packages[i-1].second;
                memcpy(dp[i], dp[i-1], sizeof(dp[i]));
                continue;
            }

            memset(g, 0, sizeof(g));
            for (int j = 0; j <= sum; ++j) {
                int md = j % packages[i-1].first;
                g[md] = (g[md] + dp[i-1][j]) % mod;
                int t = j - packages[i-1].first * (packages[i-1].second + 1);
                if (t >= 0) g[md] = (g[md] - dp[i-1][t] + mod) % mod;
                dp[i][j] = g[md];
            }
        }
        int ans = 0;
        for (int i = l; i <= std::min(r, sum); ++i) {
            ans = (1LL * dp[n][i] * (zero + 1) + ans) % mod;
        }

        return ans;
    }
};
