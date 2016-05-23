/*******************************************
 * pollard_rho
 * 将整数拆分成质因子.
 *
 * 1. 米勒-拉宾
 *   判断一个束是否为素数
 * 2. 欧几里得
 *   求两个数的最大公约数
 *
 * 根据一定规则生成x, y, 求出y-x和n的最大公约数, 若不为1则为整数的一个因子.
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

type gcd (type a, type b) {
	return b == 0 ? a : gcd(b, a%b);
}

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

type pollard_rho(type n, type tmp) {
	int i = 1, k = 2;
	type x = rand() % n;
	type y = x;

	while(true) {
		i++;
		x = ( mul_mod(x, x, n) + tmp) % n;
		type d = gcd( (y > x ? y - x : x - y), n);
		if (d != 1 && d != n)
			return d;

		if (y == x)
			return n;

		if (i == k) {
			y = x;
			k <<= 1;
		}
	}
}

void findfactor (int& cnt, type* factor, type n) {
	if(miller_rabin(n)) {
		factor[cnt++] = n;
		return;
	}

	type p = n;
	while(p >= n)
		p = pollard_rho(p, rand() % (n-1) + 1);

	findfactor (cnt, factor, p);
	findfactor (cnt, factor, n / p);
}

void pollard_divfactor (int& cnt, type* factor, type n) {
	cnt = 0;
	srand(time(0));
	findfactor(cnt, factor, n);
}
