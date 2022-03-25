class Solution {
public:
    int get(int x, int y, vector<vector<int>>& sum) {
        if (x < 0 || y < 0) {
            return 0;
        }
        return sum[x][y];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> sum;
        int m = matrix.size();
        int n = matrix[0].size();
        sum.resize(m);
        for (int i = 0; i < m; ++i) {
            sum[i].resize(n);
            for (int j = 0; j < n; ++j) {
                sum[i][j] = matrix[i][j] == '1' ? 1 : 0;
                sum[i][j] += get(i-1, j, sum) + get(i, j-1, sum) - get(i-1, j-1, sum);
            }
        }

        for (int k = min(m, n); k; --k) {
            for (int i = k-1; i < m; ++i) {
                for (int j = k-1; j < n; ++j) {
                    int s = get(i, j, sum) - get(i-k, j, sum) - get(i, j-k, sum) + get(i-k, j-k, sum);
                    if (s == k*k) {
                        return s;
                    }
                }
            }
        }
        return 0;
    }
};
