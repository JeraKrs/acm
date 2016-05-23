#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define lowbit(x) ((x)&(-x))
const int maxn = 1e3;

/*************一维****************/
int fenw[maxn+5];
void fenwick_add (int x, int v) {
	while (x <= maxn) {
		fenw[x] += v;
		x += lowbit(x);
	}
}
int fenwick_sum (int x) {
	int ret = 0;
	while (x) {
		ret += fenw[x];
		x -= lowbit(x);
	}
	return ret;
}
int fenwick_find (int x) {
	 int p = 0, ret = 0;
	 for (int i = 20; i >= 0; i--) {
		 p += (1<<i);
		 if (p > maxn || ret + fenw[p] >= x)
			 p -= (1<<i);
		 else
			 ret += fenw[p];
	 }
	 return p + 1;
}

/*************二维****************/
int fenw[maxn+5][maxn+5];
void fenwick_add (int x, int y, int a) {
    for (int i = x; i <= maxn; i += lowbit(i)) {
        for (int j = y; j <= maxn; j += lowbit(j))
            fenw[i][j] += a;
    }
}
int fenwick_sum(int x, int y) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j))
            ret += fenw[i][j];
    }
    return ret;
}

