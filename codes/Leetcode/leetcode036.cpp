class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			int n = 9, c[9];
			bool change = true;

			for (int i = 0; i < n; i++) {
				// Row
				for (int k = 0; k < n; k++)  c[k] = 0;
				for (int k = 0; k < n; k++) {
					if (board[i][k] != '.') {
						c[board[i][k]-'1']++;
						if (c[board[i][k]-'1'] > 1)
							return false;
					}
				}

				// Column
				for (int k = 0; k < n; k++)  c[k] = 0;
				for (int k = 0; k < n; k++) {
					if (board[k][i] != '.') { 
						c[board[k][i]-'1']++;
						if (c[board[k][i]-'1'] > 1)
							return false;
					}
				}

				// Block
				for (int k = 0; k < n; k++)  c[k] = 0;
				for (int k = 0; k < n; k++) {
					int x = i / 3 * 3 + k / 3, y = i % 3 * 3 + k % 3;
					if (board[x][y] != '.') {
						c[board[x][y]-'1']++;
						if (c[board[x][y]-'1'] > 1)
							return false;
					}
				}
			}
			return true;
		}
};
