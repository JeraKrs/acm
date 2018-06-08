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

		int dfs(int d, int n, int* pos) {
			if (d >= n) { return 1; }

			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (check(d, i, pos) == false) continue;

				pos[d] = i;
				ans += dfs(d + 1, n, pos);
			}
			return ans;
		}

		int totalNQueens(int n) {
			int* pos = new int[n];
			int ans = dfs(0, n, pos);
			delete pos;
			return ans;
		}
};
