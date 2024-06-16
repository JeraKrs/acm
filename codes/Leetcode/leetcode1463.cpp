class Solution {
public:
    int hash(int x, int y, int n) {
        return std::min(x, y) * n + std::max(x, y);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int hash_size = col * col;
        std::vector<int> records[2];
        records[0].resize(hash_size, -1);
        records[1].resize(hash_size, -1);

        std::queue<pair<int, int>> que;
        que.push(make_pair(0, col-1));
        records[0][hash(0, col-1, col)] = grid[0][0] + grid[0][col-1];

        for (int i = 1; i < row; ++i) { // 每层
            int index = (i&1);
            int size = que.size();
            records[index].assign(hash_size, -1);

            while (size--) { // 上一层可遍历到的位置
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                int score = records[index^1][hash(x, y, col)];

                for (int dx = -1; dx <= 1; ++dx) {
                    int xx = x + dx;
                    if (xx < 0 || xx >= col) continue;
                    for (int dy = -1; dy <= 1; ++dy) {
                        int yy = y + dy;
                        if (yy < 0 || yy >= col) continue;
                        int new_position = hash(xx, yy, col);
                        int new_score = score + grid[i][xx] + grid[i][yy];
                        if (xx == yy) {
                            new_score -= grid[i][xx];
                        }
                        if (records[index][new_position] < new_score) {
                            if (records[index][new_position] == -1) {
                                que.push(make_pair(xx, yy));
                            }
                            records[index][new_position] = new_score;
                        }
                    }
                }
            }
        }

        int ans = 0;
        while (!que.empty()) {
            int index = (row-1)&1;
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            ans = std::max(ans, records[index][hash(x, y, col)]);
        }
        return ans;
    }
};
