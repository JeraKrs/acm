class Solution {
	public:
		bool check(int x, int y, int* pos) {
			for (int i = 0; i < x; i++) {
				if (y == pos[i]) return false;
				if (y - x == pos[i] - i) return false;
				if (x + y == pos[i] + i) return false;
			}
			return true;
		}

		void dfs(int d, int n, int* pos, vector<vector<string>>& ans, vector<string>& m) {
			if (d >= n) { ans.push_back(m); return; }

			for (int i = 0; i < n; i++) {
				if (check(d, i, pos) == false) continue;

				pos[d] = i;
				m[d][i] = 'Q';

				dfs(d + 1, n, pos, ans, m);
				m[d][i] = '.';
			}
		}

		vector<vector<string>> solveNQueens(int n) {
			string s = "";
			for (int i = 0; i < n; i++) s = s+'.';
			vector<string> m;
			for (int i = 0; i < n; i++) m.push_back(s);

			vector<vector<string>> ans;
			int* pos = new int[n];

			dfs(0, n, pos, ans, m);

			delete pos;
			return ans;
		}
};
