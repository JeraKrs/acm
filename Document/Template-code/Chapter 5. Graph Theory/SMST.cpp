#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e4 + 5; // The number of Node;
const int maxm = 1e6 + 5; // The number of Edge;
const int inf = 0x3f3f3f3f;

struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {}
	bool operator < (const Edge& a) const { return w < a.w; }
}E[maxm];

int N, M, F[maxn], D[maxn][maxn], use[maxm];
vector<pii> G[maxn];

int find (int x) { return x == F[x] ? x : F[x] = find(F[x]); }

void dfs (int u, int fa, int w, int* d) {
	d[u] = w;

	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].first;
		if (v == fa) continue;
		dfs(v, u, max(w, G[u][i].second), d);
	}
}

int Kruskal(int n, int m, Edge* e) {
	int ret = 0;
	sort(e, e + m);
	for (int i = 0; i <= n; i++) F[i] = i;

	for (int i = 0; i < m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) != find(v)) {
			n--;
			use[i] = 1;
			ret += w;
			F[find(u)] = find(v);
			G[u].push_back(make_pair(v, w));
			G[v].push_back(make_pair(u, w));
		}
	}
	if (n != 1) {} // Can not build a MST
	return ret;
}

int SMST (int n, int m, Edge* e) {
	for (int i = 0; i <= n; i++) {
		F[i] = i;
		G[i].clear();
	}
	memset(use, 0, sizeof(use));

	int ans = Kruskal(n, m, e), ret = inf;
	for (int i = 1; i <= N; i++)
		dfs(i, 0, 0, D[i]);
	for (int i = 0; i < M; i++) {
		if (use[i]) continue;
		int u = e[i].u, v = e[i].v, w = e[i].w;
		ret = min(ret, ans + w - D[u][v]);
	}
	return ret;
}

int main () {
	return 0;
}
