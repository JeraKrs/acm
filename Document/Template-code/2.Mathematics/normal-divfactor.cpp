/*******************************************
 * 试除法分解因子
 * 将一个数分解成质因子.
 *
 * 1. 米勒-拉宾
 *   判断一个数为素数
 *
 * 枚举2~sqrt(n)的数，判断是否为n的因子.
 * 复杂度为o(sqrt(n)).
********************************************/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long type;

void div_factor (int& cnt, type* factor, type n) {
	cnt = 0;

	type m = (type)sqrt(n+0.5);
	for (type i = 2; i <= n && i <= m; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				factor[cnt++] = i;
				n /= i;
			}
		}
		/* 可以通过用miller-rabin算法判断进行优化
		if (miller_rabin(n)) {
			factor[cnt++] = n;
			return;
		}
		*/
	}

	if (n != 1)
		factor[cnt++] = n;
}
