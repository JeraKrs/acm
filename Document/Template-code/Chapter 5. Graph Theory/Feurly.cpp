#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const int maxn = 1005;

int top = 0, vis[maxn], path[maxn];
vector<pii> G[maxn];

void feurly (int u) {
	for (int i = 0; i < G[u].size(); i++) {
		int e = G[u][i].first, v = G[u][i].second;
		if (vis[e]) continue;
		vis[e] = 1;
		feurly(v);
		path[top++] = e;
	}
}

int main () {
	return 0;
}
