/**********************
 * 欧几里得算法：求出a和b的最大公约数d；
 *
 * 拓展欧几里得算法：求解线性方程的解
 * a * x + b * y = d；
 * 保证求出的解|x|+|y|最小。
 * d为a和b的最大公约数，即当有线性方程a * x + b * y = c，d = gcd(a,b)，c % d != 0时，方程无解。
**********************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

type gcd(type a, type b) {
	return b == 0 ? a : gcd(b, a%b);
}

void exgcd(type a, type b, type& d, type& x, type& y) {
	if (!b)
		d = a, x = 1, y = 0;
	else {
		exgcd(b, a%b, d, y, x);
		y-= x * (a/b);
	}
}
