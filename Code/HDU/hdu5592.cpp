#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 50005;
#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)|1)

int lc[maxn<<2], rc[maxn<<2], sz[maxn<<2];

void pushup(int u) {
	sz[u] = sz[lson(u)] + sz[rson(u)];
}

void build (int u, int l, int r) {
	lc[u] = l, rc[u] = r;
	sz[u] = 1;

	if (l == r) return;

	int mid = (l + r) >> 1;
	build (lson(u), l, mid);
	build (rson(u), mid+1, r);
	pushup(u);
}

void modify(int u, int x, int v) {
	if (x == lc[u] && rc[u] == x) {
		sz[u] = v;
		return;
	}

	int mid = (lc[u] + rc[u]) >> 1;
	if (x <= mid) modify(lson(u), x, v);
	else modify(rson(u), x, v);
	pushup(u);
}

int search(int u, int k) {
	if (lc[u] == rc[u]) return lc[u];

	if (sz[lson(u)] >= k) return search(lson(u), k);
	else return search(rson(u), k - sz[lson(u)]);
}

int N, A[maxn], ans[maxn];

int main () {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &N);
		A[0] = 0;
		for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
		build(1, 0, N-1);
		for (int i = N; i; i--) {
			ans[i] = search(1, A[i] - A[i-1] + 1);
			modify(1, ans[i], 0);
		}
		for (int i = 1; i <= N; i++)
			printf("%d%c", N-ans[i], i == N ? '\n' : ' ');
	}
	return 0;
}
