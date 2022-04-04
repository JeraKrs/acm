class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> pre_status = board;
        int dir[8][2] = {
            {1, 1}, {1, 0}, {1, -1}, {0, 1},
            {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = 0;
                for (int d = 0; d < 8; ++d) {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    c += pre_status[x][y];
                }
                if (c < 2 || c > 3) {
                    board[i][j] = 0;
                } else if (c == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
