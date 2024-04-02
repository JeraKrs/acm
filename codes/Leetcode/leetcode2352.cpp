class Solution {
public:
    bool judge(int row, int col, const vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            if (grid[row][i] != grid[i][col]) return false;
        }
        return true;
    }

    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (judge(row, col, grid)) ++ans;
            }
        }
        return ans;
    }
};
