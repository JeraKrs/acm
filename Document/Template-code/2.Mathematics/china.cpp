/**********************
 * 中国剩余定理（孙子定理）
 * 在多个线性模方程下，x = ai % mi(保证mi和mj在i≠的情况下互质)
 * 令M = 所有mi的积，wi = M / mi，且gcd(wi,mi)=1
 * 用拓展欧几里得求出pi和qi，使得wi*pi + mi*qi = 1
 * 令ei = wi * pi，则方程组的解为x = (e1*a1 + e2*a2 + ... + en*an) % M
 * 即在M的剩余系中x有唯一解
**********************/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long type;

void exgcd (type a, type b, type& d, type& x, type& y) {
	if (b == 0)
		d = a, x = 1, y = 0;
	else {
		exgcd(b, a%b, d, y, x);
		y -= (a/b) * x;
	}
}

type china (type* a, type* m, int n) {
	type Mi = 1;
	for (int i = 0; i < n; i++)
		Mi *= m[i];

	type ret = 0;
	for (int i = 0; i < n; i++) {
		type w = Mi/m[i], d, x, y;
		exgcd(m[i], w, d, x, y);

		ret = (ret + y*w*a[i]) % Mi;
	}
	return (ret % Mi + Mi) % Mi;
}
