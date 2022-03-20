class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp;

        int m = dungeon.size();
        int n = dungeon[0].size();
        dp.resize(m);

        for (int i = m-1; i >= 0; --i) {
            dp[i].resize(n);

            for (int j = n - 1; j >= 0; --j) {
                int minv;

                if (i + 1 == m && j + 1 == n) {
                    minv = 1;
                } else if (i + 1 == m) {
                    minv = dp[i][j+1];
                } else if (j + 1 == n) {
                    minv = dp[i+1][j];
                } else {
                    minv = min(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = max(1, minv - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};
