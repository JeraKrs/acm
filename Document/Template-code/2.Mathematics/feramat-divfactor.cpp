/*******************************************
 * 费马方法（feramat)
 * 将整数拆分成质因子.
 *
 * 1. 米勒-拉宾
 *   判断一个数是否为素数
 *
 * 一个整数N, 可以分解成一个奇数上2^k次方,即N = (2 * n + 1) * 2^k;
 * 令M = 2 * n + 1, 如果M 不为素数, 那么M 肯定可以拆分成两个奇数相乘M = c * d;
 * 假设c >= d, 令a = (c + d) / 2, b = (c - d) / 2;
 * 那么M = a * a - b * b = 4 * (c + d) / 4;
 * 于是这要枚举a, 保证a * a - M为完全平数即可.
 *
 * 对于因子为比较大的素数, 并且个数比较少的情况来说,复杂度仍比较高.
********************************************/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime> // possible need;
#include <cstdlib> // possible need;
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long type;

type mul_mod (type a, type b, type mod) {
	type ret = 0;
	while (b) {
		if (b&1)
			ret = (ret + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ret;
}

type pow_mod (type a, type n, type mod) {
	type ans = 1;
	while (n) {
		if (n&1)
			ans = mul_mod(ans, a, mod);
		a = mul_mod(a, a, mod);
		n >>= 1;
	}
	return ans;
}

bool miller_rabin(type n) {
	if (n < 2)
		return false;

	srand(time(0));
	for (int i = 0; i < 20; i++)
		if (pow_mod(rand() % (n-1) + 1, n-1, n) != 1)
			return false;
	return true;
}

void feramat_factor (int& cnt, type* factor, type n) {
	if (miller_rabin(n)) {
		factor[cnt++] = n;
		return;
	}

	type x = (type) sqrt(n + 0.5);
	while (x < n) {
		type w = x * x - n;
		type y = (type) sqrt(w + 0.5);
		if (w == y * y) {
			feramat_factor(cnt, factor, x+y);
			feramat_factor(cnt, factor, x-y);
			break;
		}
		x++;
	}
}

void feramat_divfactor (int& cnt, type* factor, type n) { // N = (2*n+1) * 2^k;
	cnt = 0;
	if (n == 0)
		return;

	while ((n&1) == 0) {
		factor[cnt++] = 2;
		n >>= 1;
	}

	if (n == 1)
		factor[cnt++] = n;
	else
		feramat_factor(cnt, factor, n);
}
