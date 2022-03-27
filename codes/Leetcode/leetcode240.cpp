class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = matrix[0].size();
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] > target) {
                return false;
            }
            int k = lower_bound(
                matrix[i].begin(), matrix[i].begin() + t, target) - matrix[i].begin();
            
            if (k < matrix[i].size() && matrix[i][k] == target) {
                return true;
            }
            t = min(t, k + 1);
        }
        return false;
    }
};
