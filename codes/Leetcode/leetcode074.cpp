class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			if (matrix.size() == 0 || matrix[0].size() == 0) return false;
			int l = 0, r = matrix.size();
			while (l + 1 < r) {
				int mid = (l + r) >> 1;
				if (matrix[mid][0] <= target) l = mid;
				else r = mid;
			}
			int p = l;
			l = 0, r = matrix[p].size();
			while (l + 1 < r) {
				int mid = (l + r) >> 1;
				if (matrix[p][mid] <= target) l = mid;
				else r = mid;
			} 
			return matrix[p][l] == target;
		}
};
