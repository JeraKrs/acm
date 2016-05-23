/*******************************************
 * 模方程
 *
 * (a * b) % mod = ((a % mod) * (b % mod)) % mod
********************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

type mul_mod (type a, type b, type mod) { // 当mod^2 > inf 时
	type ret = 0;
	while (b) {
		if (b&1)
			ret = (ret + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ret;
}

type pow_mod (type a, type n, type mod) { // mod <= 1e18;
	type ret = 1;
	while (n) {
		if (n&1)
			ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}
