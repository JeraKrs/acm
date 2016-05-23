/*******************************************
 * 埃拉托斯特尼素数筛选法
 * 筛选一定范围内的所有素数.
 *
 * 复杂度近似于o(n), 所以数据处理范围为1e6-1e7可以接受.
********************************************/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

void sieve(int n) {
	int m = (int)sqrt(n+0.5);
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= m; i++) {
		if (!vis[i]) {
			for (int j = i * i; j <= n; j++)
				vis[j] = 1;
		}
	}
}

int prime_table (int n, int* pri) { // 返回n以内素数个数。
	sieve(n);
	int c = 0;
	for (int i = 2; i <= n; i++)
		if (!vis[i])
			pri[c++] = i;
	return c;
}
