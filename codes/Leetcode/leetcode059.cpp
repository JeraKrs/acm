class Solution {
	public:
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> ans;
			vector<int> tmp;
			for (int i = 0; i < n; i++) tmp.push_back(0);
			for (int i = 0; i < n; i++) ans.push_back(tmp);

			int d_x[4] = {0, 1, 0, -1};
			int d_y[4] = {1, 0, -1, 0};
			int d = 0, x = 0, y = 0, m = n*n;
			while (m--) {
				ans[x][y] = n*n - m;

				int xx = x + d_x[d], yy = y + d_y[d];
				while (m && (xx<0 || xx>=n || yy<0 || yy>=n || ans[xx][yy] != 0)) {
					d = (d + 1) % 4;
					xx = x + d_x[d];
					yy = y + d_y[d];
				}
				x = xx, y = yy;
			}
			return ans;
		}
};
