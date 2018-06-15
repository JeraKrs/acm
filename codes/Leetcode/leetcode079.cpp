class Solution {
	public:
		bool dfs(int x, int y, int k, string word, vector<vector<char>>& board, vector<vector<bool>>& gph) {
			if (k >= word.size()) return true;

			int m = board.size(), n = board[0].size();

			if (x < 0 || x >= m) return false;
			if (y < 0 || y >= n) return false;
			if (board[x][y] != word[k]) return false;
			if (gph[x][y]) return false;
			gph[x][y] = true;

			int dx[] = {0, 1, 0, -1};
			int dy[] = {1, 0, -1, 0};

			for (int d = 0; d < 4; d++) {
				if (dfs(x + dx[d], y + dy[d], k + 1, word, board, gph))
					return true;
			}

			gph[x][y] = false;
			return false;
		}

		bool exist(vector<vector<char>>& board, string word) {

			int l = word.size();
			if (l == 0) return true;

			int m = board.size();
			if (m == 0) return false;

			int n = board[0].size();
			if (n == 0) return false;

			vector<vector<bool>> gph;
			vector<bool> tmp;
			for (int i = 0; i < n; i++) tmp.push_back(false);
			for (int i = 0; i < m; i++) gph.push_back(tmp);

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (dfs(i, j, 0, word, board, gph))
						return true;
				}
			}
			return false;
		}
};
