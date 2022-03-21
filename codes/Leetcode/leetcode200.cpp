class Solution {
public:
    
    void fill(int x, int y, int m, int n, vector<vector<char>>& grid) {
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> que;
        grid[x][y] = '0';
        que.push(make_pair(x, y));
        while (!que.empty()) {
            x = que.front().first;
            y = que.front().second;
            que.pop();
            for (int d = 0; d < 4; ++d) {
                int xx = x + dir[d][0];
                int yy = y + dir[d][1];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == '1') {
                    grid[xx][yy] = '0';
                    que.push(make_pair(xx, yy));
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    fill(i, j, m, n, grid);
                }
            }
        }
        return ans;
    }
};
