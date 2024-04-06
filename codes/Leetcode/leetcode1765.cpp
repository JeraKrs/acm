class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        std::vector<std::vector<int>> height;
        int m = isWater.size();
        int n = isWater[0].size();
        height.resize(m);
        for (int i = 0; i < m; ++i) height[i].resize(n, 0);

        std::queue<pair<int,int>> que;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    que.push(make_pair(i, j));
                }
            }
        }

        int dir[] = {0, -1, 0, 1, 0};
        while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            int h = height[x][y];
            for (int i = 0; i < 4; ++i) {
                int xx = x + dir[i];
                int yy = y + dir[i+1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (isWater[xx][yy] || height[xx][yy]) continue;
                height[xx][yy] = h + 1;
                que.push(make_pair(xx, yy));
            }
        }
        return height;
    }
};
