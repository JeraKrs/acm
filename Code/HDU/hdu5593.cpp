#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 500005;

int N, K, E, first[maxn], jump[maxn], linker[maxn];
int ans, dp[maxn][15];

void addEdge (int u, int v) {
	jump[E] = first[u];
	linker[E] = v;
	first[u] = E++;
}

void init () {

	int a, b;
	scanf("%d%d%d%d", &N, &K, &a, &b);

	ans = E = 0;
	first[1] = -1;
	for (int i = 2; i <= N; i++) {
		first[i] = -1;
		int f = (1LL * a * i + b) % (i-1) + 1;
		addEdge(f, i);
	}
}

void dfs(int u) {
	memset(dp[u], 0, sizeof(dp[u]));
	dp[u][0] = 1;

	for (int i = first[u]; i + 1; i = jump[i]) {
		int v = linker[i];
		dfs(v);
		for (int j = 1; j <= K; j++)
			dp[u][j] += dp[v][j-1];
	}
}

void dfs(int u, int* a) {
	int sum = 0;
	for (int i = 0; i <= K; i++)
		sum += a[i] + dp[u][i];
	ans ^= sum;

	for (int i = first[u]; i + 1; i = jump[i]) {
		int v = linker[i];
		for (int j = 1; j <= K; j++) dp[u][j] -= dp[v][j-1];
		for (int j = 0; j <= K; j++) a[j] += dp[u][j];

		int tmp[15];
		tmp[0] = 0;
		for (int j = 1; j <= K; j++) tmp[j] = a[j-1];

		dfs(v, tmp);

		for (int j = 0; j <= K; j++) a[j] -= dp[u][j];
		for (int j = 1; j <= K; j++) dp[u][j] += dp[v][j-1];
	}
}

int main () {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		init();
		dfs(1);

		int tmp[15];
		memset(tmp, 0, sizeof(tmp));
		dfs(1, tmp);
		printf("%d\n", ans);
	}
	return 0;
}
