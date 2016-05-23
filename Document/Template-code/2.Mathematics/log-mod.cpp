/**********************
 * 离散对数（大步小步算法）
 * 求解a^x = b % mod（mod为素数）
 *
 * 根据欧拉定理，只需要检查x=0,1..mod-1是不是解即可（a^(mod-1) % mod = 1）
 * 算法：先检查前m项，m取sqrt(mod)，并且计算出a^m的逆a^-m
 * 然后考虑m+1 ~ 2m项，假设存在ei * a^m = b % mod，两边同乘a^-m得ei = b' % mod
 * 所以每次将b乘以a^-m之后在1~m中查找即可（map优化）
 * 之所以m取sqrt(mod)是因为在此时复杂度最低
**********************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
typedef long long type;

type mul_mod (type a, type b, type mod) {
	return (type)a * b % mod;
}
type pow_mod (type a, type n, type mod) {
	type ans = 1;
	while (n) {
		if (n&1)
			ans = mul_mod(ans, a, mod);
		a = mul_mod(a, a, mod);
		n /= 2;
	}
	return ans;
}
void exgcd (type a, type b, type& d, type& x, type& y) {
	if (!b)
		d = a, x = 1, y = 0;
	else {
		exgcd (b, a%b, d, y, x);
		y -= x * (a/b);
	}
}
type inv (type a, type mod) {
	type d, x, y;
	exgcd(a, mod, d, x, y);
	return d == 1 ? (x+mod)% mod : -1;
}

int log_mod (type a, type b, type mod) {
	type m = (type)sqrt(mod+0.5), v, e = 1;
	v = inv(pow_mod(a, m, mod), mod); //  计算a^(-m)
	map<type, type> g;

	g[1] = 0;
	for (int i = 1; i < m; i++) {
		e = mul_mod(e, a, mod);
		if (!g.count(e)) // 记录e^i
			g[e] = i; 
	}

	for (int i = 0; i < m; i++) {
		if (g.count(b))
			return i*m+g[b];
		b = mul_mod(b, v, mod);
	}
	return -1;
}
