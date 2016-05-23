#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e6 + 5;

struct Bipartite {
	int n, color[maxn];
	vector<int> g[maxn];

	void init (int n) {
		this->n = n;
		memset(color, -1, sizeof(color));
		for (int i = 0; i <= n; i++) g[i].clear();
	}

	void addEdge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}

	bool dfs(int u) {
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (color[u] == color[v]) return false;
			if (!color[v]) {
				color[v] = 3 - color[u];
				if (!dfs(v)) return false;
			}
		}
		return true;
	}
};

int main () {
	return 0;
}
