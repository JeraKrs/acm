class Solution {
public:

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        
        // init
        int n = coins.size();
        std::vector<std::vector<int> > graph;
        graph.resize(n);

        // build tree
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        const int MAX_HALF = 15;
        int dp[n][MAX_HALF][2];

        function<void(int, int)> dfs = [&](int root, int father) {
            int coin = coins[root];
            for (int i = 0; i < MAX_HALF; ++i) {
                dp[root][i][0] = coin - k;
                dp[root][i][1] = i ? coin : -1e9;
                coin >>= 1;
            }

            for (int i = 0; i < graph[root].size(); ++i) {
                if (graph[root][i] == father) continue;
                int v = graph[root][i];
                dfs(v, root);
                for (int j = 0; j <  MAX_HALF; ++j) {
                    int best = std::max(dp[v][j][0], dp[v][std::min(MAX_HALF - 1, j + 1)][1]);
                    dp[root][j][0] += best;
                    dp[root][j][1] += best;
                }
            }
        };

        dfs(0, 0);
        int ans = 0;
        for (int i = 0; i < MAX_HALF; ++i) {
            ans = std::max({ans, dp[0][i][0], dp[0][i][1]});
        }
        return ans;
    }
};
