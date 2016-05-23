#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5; // The number of Node

int dfsclock, pre[maxn];
bool iscut[maxn];
vector<int> G[maxn];

int dfs (int u, int f) {
	int lowu = pre[u] = ++dfsclock, child = 0;

	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!pre[v]) {
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u]) iscut[u] = true;
		} else if (pre[v] < pre[u] && v != f)
			lowu = min(lowu, pre[v]);
	}

	if (f < 0 && child == 1) iscut[u] = false;
	return lowu;
}

void findCutPoint(int n) {
	dfsclock = 0;
	memset(pre, 0, sizeof(pre));
	memset(iscut, 0, sizeof(iscut));
	for (int i = 1; i <= n; i++)
		if (!pre[i]) dfs(i, -1);
}

int main () {
	return 0;
}
