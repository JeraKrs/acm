#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 50005;

struct State {
	int l, r, id;
}Q[maxn];

int S, BSZ; // BSZ = sqrt(n);

bool cmp(const State& a, const State& b) {
	if (a.l / BSZ == b.l / BSZ) return a.r < b.r;
	return a.l / BSZ < b.l / BSZ;
}

ll query(int u, int v) {

	if (u) {
		for (int i = Q[u].l; i < Q[v].l; i++) { } // 删除
		for (int i = Q[v].l; i < Q[u].l; i++) { } // 增加
		for (int i = Q[u].r + 1; i <= Q[v].r; i++) { } //增加
		for (int i = Q[v].r + 1; i <= Q[u].r; i++) { } // 删除
	} else {
		for (int i = Q[v].l; i <= Q[v].r; i++) { } //预处理第一块
	}
	return S;
}

int main () {
	return 0;
}
