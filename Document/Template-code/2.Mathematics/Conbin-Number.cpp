/*******************************************
 * 组合数
 * 获取组合数.
 *
 *
 * 1. 组合数性质
 *   c[i][j] = c[i-1][j-1] + c[i-1][j];
 *   c[i][0] = c[i][i] = 1;
********************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long type;

type conbin[maxc][maxc];

void conbinatorial_number (int n, type mod) {
	for (int i = 0; i <= n; i++) {
		conbin[i][0] = conbin[i][i] = 1;
		for (int j = 1; j < i; j++)
			conbin[i][j] = (conbin[i-1][j-1] + conbin[i-1][j]) % mod;
	}
}
