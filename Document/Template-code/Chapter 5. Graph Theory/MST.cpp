#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e4 + 5; // The number of Node;
const int maxm = 1e6 + 5; // The number of Edge;

struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {}
	bool operator < (const Edge& a) const { return w < a.w; }
} E[maxm];

int F[maxn];
int find(int x) { return x == F[x] ? x : F[x] = find(F[x]); }

int Kruskal(int n, int m, Edge* e) {
	int ret = 0;
	sort(e, e + m);
	for (int i = 0; i <= n; i++) F[i] = i;

	for (int i = 0; i < m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) != find(v)) {
			F[find(u)] = find(v);
			n--;
			ret += w;
		}
	}
	if (n != 1) {} // Can not build a MST
	return ret;
}

/* 最小瓶颈树：从一个空图开始，按照权值从小到大加入，图第一次完全联通时，该图的最小生成树即为原图的最小瓶颈生成树*/
/* 最小瓶颈路：求出图的最小生成树，则起点和终点间的唯一路径上权值最大的边即为要求的瓶颈*/

int main () {
	return 0;
}
