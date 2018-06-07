class Solution {
	public:
        bool check(int x, int y, char c, vector<vector<char>>& board)  {
            for (int k = 0; k < 9; k++) {
                if (board[x][k] == c) return false;
                if (board[k][y] == c) return false;
                int i = x/3*3+k/3, j = y/3*3+k%3;
                if (board[i][j] == c) return false;
            }
            return true;
		}

		bool dfs(int x, int y, vector<vector<char>>& board) {
			while (x < 9 && board[x][y] != '.') {
				y++;
				if (y == 9) { y = 0; x++; }
			}
			if (x >= 9) return true;

			for (int k = 0; k < 9; k++) {
				if (check(x, y, '1' + k, board) == false) continue;

				board[x][y] = '1' + k;
				if (dfs(x, y, board)) return true;
				board[x][y] = '.';
			}
			return false;
		} 

		void solveSudoku(vector<vector<char>>& board) {
			int n = 9, c[9];
			set<int> G[9][9];

			// Find the possible value in '.';
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (board[i][j] == '.') {

						for (int k = 0; k < n; k++) c[k] = 0;
						for (int k = 0; k < n; k++) {
							if (board[i][k] != '.') c[board[i][k]-'1'] = 1;
							if (board[k][j] != '.') c[board[k][j]-'1'] = 1;
							int x = i / 3 * 3 + k / 3, y = j / 3 * 3 + k % 3;
							if (board[x][y] != '.') c[board[x][y]-'1'] = 1;
						}
						for (int k = 0; k < n; k++)
							if (c[k] == 0) G[i][j].insert(k);
					}
				}
			}

			bool change = true;
			while (change) {
				change = false;

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (board[i][j] != '.') continue;

						if (G[i][j].size() == 1) {
							set<int>::iterator iter = G[i][j].begin();
							board[i][j] = '1' + *iter;

						} else {
							bool only;
							for (set<int>::iterator iter = G[i][j].begin(); iter != G[i][j].end(); iter++) {

								// Row only
								only = true;
								for (int k = 0; k < n; k++) {
									if (board[i][k] != '.' || k == j) continue;
									if (G[i][k].count(*iter)) { only = false; break; }
								}
								if (only) { board[i][j] = '1' + *iter; break; }

								// Column only
								only = true;
								for (int k = 0; k < n; k++) {
									if (board[k][j] != '.' || k == i) continue;
									if (G[k][j].count(*iter)) { only = false; break; }
								}
								if (only) { board[i][j] = '1' + *iter; break; }

								only = true;
								for (int k = 0; k < n; k++) {
									int x = i/3*3 + k/3, y=j/3*3 + k%3;
									if (board[x][y] != '.' || (x == i && y == j)) continue;
									if (G[x][y].count(*iter)) { only = false; break; }
								}
								if (only) { board[i][j] = '1' + *iter; break; }
							}
						}

						// Remove
						if (board[i][j] != '.') {
							change = true;
							int f = board[i][j] - '1';
							for (int k = 0; k < n; k++) {
								if (board[i][k] == '.') G[i][k].erase(f);
								if (board[k][j] == '.') G[k][j].erase(f);
								int x = i/3*3+k/3, y = j/3*3 + k%3;
								if (board[x][y] == '.') G[x][y].erase(f);
							}
						}
					}
				}
			}

			dfs(0, 0, board);
		}
};
