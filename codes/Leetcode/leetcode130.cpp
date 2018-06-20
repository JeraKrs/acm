class Solution {
	public:
		void solve(vector<vector<char>>& board) {
			if (board.size() == 0 || board[0].size() == 0) return;
			int m = board.size(), n = board[0].size();

			vector<vector<bool>> graph;
			vector<bool> tmp;
			for (int i = 0; i < n; i++) tmp.push_back(false);
			for (int i = 0; i < m; i++) graph.push_back(tmp);

			queue<pair<int,int>> que;
			for (int i = 0; i < n; i++) {
				que.push(make_pair(0, i));
				que.push(make_pair(m-1, i));
			}

			for (int i = 0; i < m; i++) {
				que.push(make_pair(i, 0));
				que.push(make_pair(i, n-1));
			}
			int dx[] = {0, 1, 0, -1};
			int dy[] = {1, 0, -1, 0};

			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				if (graph[x][y]) continue;
				graph[x][y] = true;

				for (int d = 0; d < 4; d++) {
					int xx = x + dx[d];
					int yy = y + dy[d];
					if (xx < 0 || xx >= m) continue;
					if (yy < 0 || yy >= n) continue;
					if (graph[xx][yy] || board[xx][yy] != board[x][y]) continue;
					que.push(make_pair(xx, yy));
				}
			} 


			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (graph[i][j] == false)
						board[i][j] = 'X';
				}
			}
		}
};
