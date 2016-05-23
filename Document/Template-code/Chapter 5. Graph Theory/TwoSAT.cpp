#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

struct TwoSAT {
	int n, s[maxn * 2], c;
	bool mark[maxn * 2];
	vector<int> g[maxn * 2];

	void init (int n) {
		this->n = n;
		memset(mark, false, sizeof(mark));
		for (int i = 0; i < n*2; i++) g[i].clear();
	}

	void addClause(int x, int xval, int y, int yval) { // (sx || sy)
		x = x * 2 + xval;
		y = y * 2 + yval;
		g[x^1].push_back(y);
		g[y^1].push_back(x);
	}

	bool dfs (int x) {
		if (mark[x^1]) return false;
		if (mark[x]) return true;
		mark[x] = true;
		s[c++] = x;

		for (int i = 0; i < g[x].size(); i++)
			if (!dfs(g[x][i])) return false;
		return true;
	}

	bool solve () {
		for (int i = 0; i < n*2; i += 2) {
			if (!mark[i] && !mark[i+1]) {
				c = 0;
				if (!dfs(i)) {
					while (c) mark[s[--c]] = false;
					if (!dfs(i+1)) return false;
				}
			}
		}
		return true;
	}
};

int main () {
	return 0;
}
