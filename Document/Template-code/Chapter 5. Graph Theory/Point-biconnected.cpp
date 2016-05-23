#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

struct Edge {
	int from, to, val;
	Edge(int from = 0, int to = 0, int val = 0): from(from), to(to), val(val) {}
};

int dfsclock, cntbcc, pre[maxn], bccno[maxn];
bool iscut[maxn];
vector<int> G[maxn], BCC[maxn];
stack<Edge> S;

// 割顶的bccno无意义
int dfs (int u, int fa) {
	int lowu = pre[u] = ++dfsclock, child = 0;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		Edge e = Edge(u, v);
		if (!pre[v]) {
			child++;
			S.push(e);
			int lowv = min(lowu, lowv);
			if (lowv >= pre[u]) {
				iscut[u] = 1;
				BCC[++cntbcc].clear();
				while (true) {
					Edge x = S.top();
					S.pop();
					if (bccno[x.from] != cntbcc) {
						BCC[cntbcc].push_back(x.from);
						bccno[x.from] = cntbcc;
					}

					if (bccno[x.to] != cntbcc) {
						BCC[cntbcc].push_back(x.to);
						bccno[x.to] = cntbcc;
					}
					if (x.from == u && x.to == v) break;
				}
			}
		} else if (pre[v] < pre[u] && v != fa) {
			S.push(e);
			lowu = min(lowu, pre[v]);
		}
	}
	if (fa < 0 && child == 1) iscut[u] = 0;
	return lowu;
}

void findBCC(int n) {
	dfsclock = cntbcc = 0;
	memset(pre, 0, sizeof(pre));
	memset(iscut, 0, sizeof(iscut));
	memset(bccno, 0, sizeof(bccno));
	for (int i = 0; i < n; i++)
		if (!pre[i]) dfs(i, -1);
}

int main () {
	return 0;
}
