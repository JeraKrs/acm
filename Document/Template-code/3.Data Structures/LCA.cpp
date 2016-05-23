#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const int maxn = 10005;
const int inf = 0x3f3f3f3f;
const int BIT = 20;

int dep[maxn], far[maxn][BIT+5];
vector<int> G[maxn];
queue<int> que;

void ST (int n) {
	for (int k = 1; k <= BIT; k++) {
		for (int i = 1; i <= n; i++) 
			far[i][k] = far[far[i][k-1]][k-1];
	}

	memset(dep, inf, sizeof(dep));
	for (int i = 1; i <= n; i++) if (far[i][0] == 0) {
		dep[i] = 0; que.push(i);
	}

	while (!que.empty()) {
		int u = que.front();
		que.pop();

		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			if (dep[v] > dep[u] + 1) {
				dep[v] = dep[u] + 1;
				que.push(v);
			}
		}
	}
}

int LCA(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);

	int mv = dep[v] - dep[u];
	for (int i = 0; i <= BIT && mv; mv >>= 1, i++)
		if (mv&1) v = far[v][i];

	if (u == v) return u;

	for (int i = BIT; i >= 0; i--) {
		if (far[u][i] == far[v][i]) continue;
		u = far[u][i]; v = far[v][i];
	}
	return far[u][0];
}

int main () {
	return 0;
}
