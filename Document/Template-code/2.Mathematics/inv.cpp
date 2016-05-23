/**********************
 * 逆元：a * inv(a,mod) % mod = 1;
**********************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long type;

type inv (type a, type mod) {
	type d, x, y;
	exgcd(a, mod, d, x, y);
	return d == 1 ? (x+mod)%mod : -1;
}

type inv (type a, type mod) { // 费马小定理，a^(mod-1) % mod = 1;
	return pow_mod(a, mod-2, mod);
}
