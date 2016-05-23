#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

stack<int> S;
vector<int> G[maxn];
int dfsclock, cntscc, sccno[maxn], pre[maxn];

int dfs(int u) {
	int lowu = pre[u] = ++dfsclock;
	S.push(u);

	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!pre[v]) {
			int lowv = dfs(v);
			lowu = min(lowu, lowv);
		} else if (!sccno[v]) 
			lowu = min(lowu, pre[v]);
	}

	if (lowu == pre[u]) {
		cntscc++;
		while (true) {
			int x = S.top();
			S.pop();
			sccno[x] = cntscc;
			if (x == u) break;
		}
	}
	return lowu;
}

void findSCC(int n) {
	dfsclock = cntscc = 0;
	memset(pre, 0, sizeof(pre));
	memset(sccno, 0, sizeof(sccno));
	for (int i = 0; i < n; i++)
		if (!pre[i]) dfs(i);
}

int main () {
	return 0;
}
