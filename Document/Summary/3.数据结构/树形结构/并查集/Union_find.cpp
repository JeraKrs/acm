#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

// 普通;
int f[maxn];

void UF_init(int n) {
	for (int i = 0; i <= n; i++)
		f[i] = i;
}

int UF_find(int x) {
	return x == f[x] ? x : f[x] = UF_find(f[x]);
}

void UF_union(int u, int v) {
	int fu = UF_find(u);
	int fv = UF_find(v);
	if (fu != fv)
		f[fu] = fv;
}

// 加权;
int f[maxn], r[maxn], relat = 3;

void UF_init(int n) {
	for (int i = 0; i <= n; i++) {
		f[i] = i;
		r[i] = 0;
	}
}

int UF_find(int x) {
	if (f[x] == x)
		return x;

	int fx = UF_find(x);
	// According Problem;
	r[x] = (r[x] + r[fx]) % relat;
	return f[x] = fx;
}

bool UF_union(int u, int v, int rel) {
	int fu = UF_find(u);
	int fv = UF_find(v);

	if (fu != fv) {
		// According Problem;
		r[fu] = ((r[v] + rel - r[u]) % relat + relat) % relat;
		f[fu] = fv;
	} else
		return ((f[u] - f[v]) % relat + relat) % relat == rel;
	return true;
}

// 按秩合并；
struct UFSet {
	int parent, root;
}f[maxn];

void UF_init(int n) {
	for (int i = 0; i <= n; i++) {
		f[i].parent = 1;
		f[i].root = 1;
	}
}

int UF_find(int x) {
	int p, q, tmp;
	p = q = x;
	while (!f[p].root)
		p = f[p].parent;

	while (q != p) {
		tmp = f[q].parent;
		f[q].parent = p;
		q = tmp;
	}
	return p;
}

void UF_union(int u, int v) {
	int fu = UF_find(u);
	int fv = UF_find(v);

	if  (f[fu].parent < f[fv].parent)
		swap(fu, fv);
	f[fu].parent += f[fv].parent;
	f[fv].parent = fu;
	f[fv].root = 0;
}
