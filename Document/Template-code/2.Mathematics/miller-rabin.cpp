/*******************************************
 * 米勒-拉宾算法(miller-rabin)
 * 判断一个数是否为素数.
 *
 * 1. 费马小定理
 *   对于一个素数来说，a^(n-1) % n 恒等于1 (1 <= a <= n-1)
 * 2. 快速幂取模
 * 3. 大数相乘（long long）取模
 *   两个long long 型的数相乘有可能大于long long型的上限
 *
 * 随机生成一个a, 判断a^(n-1) % n 是否为1, 如果不为1可以确定不是素数.
 * 对于合数来说通过测试的概率不足25%.
 * 判断一定次数，使得该数为素数的概率趋近于1.
 * 
 * 3215031751 需要测试较多次，否则会失准.
********************************************/

#include <cstdio>
#include <cstring>
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

bool miller_rabin(type n) {
	if (n < 2)
		return false;

	srand(time(0));
	for (int i = 0; i < 20; i++)
		if (pow_mod(rand() % (n-1) + 1, n-1, n) != 1)
			return false;
	return true;
}
