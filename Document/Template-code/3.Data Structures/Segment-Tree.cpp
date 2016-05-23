#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)|1)

int lc[maxn << 2], rc[maxn << 2], nd[maxn << 2], ad[maxn << 2];

inline void maintain (int u, int w) {
	// According Problem;
	nd[u] += ad[u] * (rc[u] - lc[u] + 1);
}

void pushup (int u) {
	// According Problem;
	nd[u] = nd[lson(u)] + nd[rson(u)];
}

void pushdown (int u) {
	// According Problem;
	if (ad[u]) {
		maintain(lson(u), ad[u]);
		maintain(rson(u), ad[u]);
		ad[u] = 0;
	}
}

void segtree_build (int u, int l, int r) {
	lc[u] = l;
	rc[u] = r;
	nd[u] = ad[u] = 0;

	if (l == r) {
		// According Problem;
		return;
	}

	int mid = (l + r) / 2;
	segtree_build(lson(u), l, mid);
	segtree_build(rson(u), mid + 1, r);
	pushup(u);
}

void segtree_modify (int u, int l, int r, int w) {
	if (l <= lc[u] && rc[u] <= r) {
		// According Problem;
		maintain(u, w);
		return ;
	}

	pushdown(u);
	int mid = (lc[u] + rc[u]) >> 1;
	if (l <= mid)
		segtree_modify(lson(u), l, r, w);
	if (r > mid)
		segtree_modify(rson(u), l, r, w);
	pushup(u);
}

int segtree_query (int u, int l, int r) {
	if (l <= lc[u] && rc[u] <= r)
		return nd[u];

	pushdown(u);
	int mid = (lc[u] + rc[u]) >> 1, ret = 0;
	if (l <= mid)
		ret += segtree_query(lson(u), l, r);
	if (r > mid)
		ret += segtree_query(rson(u), l, r);
	pushup(u);
	return ret;
}
