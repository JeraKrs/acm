class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector<int> ans;
			int m = matrix.size();
			if (m == 0) return ans;
			int n = matrix[0].size();
			if (n == 0) return ans;

			vector<bool> tmp;
			vector<vector<bool>> gph;
			for (int i = 0; i < n; i++) tmp.push_back(false);
			for (int i = 0; i < m; i++) gph.push_back(tmp);

			int d_x[4] = {0, 1, 0, -1};
			int d_y[4] = {1, 0, -1, 0};

			int d = 0, x = 0, y = 0, k = m * n;

			while (k--) {
				ans.push_back(matrix[x][y]);
				gph[x][y] = true;

				int xx = x + d_x[d], yy = y + d_y[d];
				while (k && (xx<0 || xx>=m || yy<0 || yy>=n || gph[xx][yy])) {
					d = (d + 1) % 4;
					xx = x + d_x[d];
					yy = y + d_y[d];
				}
				x = xx, y = yy;
			}
			return ans;
		}
};
