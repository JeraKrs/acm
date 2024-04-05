class Solution {
public:
    void trans(bool u[], bool v[], int bias, int n) {
        for (int i = 0; i <= n; ++i) {
            if (v[i] == false) continue;
            int t = i + bias;
            if (t >= 0 && t <= n) u[t] = true;
        }
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int p = m + n - 1;
        if (p&1) return false;
        p >>= 1;
        bool flags[m][n][p+1];   
        memset(flags, false, sizeof(flags));
        if (grid[0][0] == ')') return false;
        flags[0][0][1] = true;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + j == 0) continue;
                int bias = (grid[i][j] == '(' ? 1 : -1);
                if (i) trans(flags[i][j], flags[i-1][j], bias, p);
                if (j) trans(flags[i][j], flags[i][j-1], bias, p);
            }
        }

        return flags[m-1][n-1][0];
    }
};
