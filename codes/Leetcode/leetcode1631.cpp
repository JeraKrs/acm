class Solution {
public:
    static constexpr int dir[] = {0, 1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        std::vector<std::vector<int> > costs;
        costs.resize(n);
        for (int i = 0; i < n; ++i) {
            costs[i].resize(m, -1);
        }
        
        std::queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        costs[0][0] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int xx = x + dir[d];
                int yy = y + dir[d+1];

                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                int cost = std::max(costs[x][y], abs(heights[x][y] - heights[xx][yy]));
                if (costs[xx][yy] != -1 && cost >= costs[xx][yy]) continue;
                costs[xx][yy] = cost;
                q.push(make_pair(xx, yy));
            }
        }
        return costs[n-1][m-1];
    }
};
