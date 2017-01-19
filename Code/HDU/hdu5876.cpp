/******************
 * Author: Jerakrs
 * Time: 2016.10.01
 * Problem:	给定一张图不存在边，求从起点S到各个点的距离
 * Solve:	BFS，遍历点时可以用并查集做路劲压缩，经过的点不需要重复检查
* Complexity: o( n ) 并查集压缩路径复杂度为常数
******************/

#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 200005;

int N, M, S, F[maxn], A[maxn];
set<int> G[maxn];

int get(int x) {
	return x == F[x] ? x : F[x] = get(F[x]);
}

void init () {
	scanf("%d%d", &N, &M);
	memset(A, -1, sizeof(A));
	for (int i = 1; i <= N + 1; i++) {
		F[i] = i;
		G[i].clear();
	}

	int u, v;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v);
		G[u].insert(v);
		G[v].insert(u);
	}
	scanf("%d", &S);
}

void solve() {
	queue<int> que;
	que.push(S);
	A[S] = 0;
	F[S] = S + 1;

	while (!que.empty()) {
		int u = que.front();
		que.pop();

		for (int i = get(1); i <= N; i = get(i+1)) {

			if (G[u].find(i) != G[u].end() || i == u)
				continue;

			A[i] = A[u] + 1;
			F[i] = i + 1;
			que.push(i);
		}
	}

	int end = (S == N ? N - 1 : N);

	for (int i = 1; i <= N; i++) {
		if (i == S)
			continue;
		printf("%d%c", A[i], i == end ? '\n' : ' ');
	}

}

int main () {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		init();
		solve();
	}
	return 0;
}
