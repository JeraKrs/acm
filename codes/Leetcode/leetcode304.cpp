class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sum = matrix;
        for (int i = 0; i < sum.size(); ++i) {
            for (int j = 0; j < sum[i].size(); ++j) {
                if (i) sum[i][j] += sum[i-1][j];
                if (j) sum[i][j] += sum[i][j-1];
                if (i&&j) sum[i][j] -= sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2];
        if (row1) ans -= sum[row1-1][col2];
        if (col1) ans -= sum[row2][col1-1];
        if (row1 && col1) ans += sum[row1-1][col1-1];
        return ans;
    }
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
