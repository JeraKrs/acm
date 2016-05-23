
【学习总结】数学-lucas定理

####定义：
> 数论Lucas定理是用来求 $C \binom{m}{n} \% p$的值, $p$是素数.

####描述：
> $lucas(n, m, p) = lucas(n/p, m/p, p) * C\binom{m \%p}{n\%p}$
$lucas(n, 0, p) = 1$

####证明：
> 设$p$为素数，$A,B$为正整数，并且有(即$A，B$的$p$进制情况)：
$A = a_kp^k + a_{k-1}p^{k-1} + \ldots + a_1p^1 + a_0$
$B = b_kp^k + b_{k-1}p^{k-1} + \ldots + b_1p^1 + b_0$
>
因为$C\binom{j}{p} = C\binom{j-1}{p-1} * \dfrac{p}{j} = 0$  (含有因子p)
所以$(1+x)^t \pmod{p} = (1 + x^t) \pmod{p}$ (中间展开项均含有$C\binom{i}{p}$)

> 于是乎，我们让$t = A$
$(1+x)^A = (1+x)^{a_kp^k + a_{k-1}p^{k-1} + \ldots + a_1p^1 + a_0} \pmod{p}$
                $=(1+x)^{a_kp^k} * (1+x)^{a_{k-1}p^{k-1}} * \ldots * (1+x)^{a_0} \pmod{p}$
                $=(1+x^{p^k})^{a_k} * (1+x^{p^k-1})^{a_{k-1}} * \ldots * (1+x)^{a_0} \pmod{p}$
对比两边$x^b$的系数，根据多项式定理和p进制数的性质(A对应的p进制，导致了系数的确定)
$C\binom{B}{A} = C\binom{b_k}{a_k} * C\binom{b_{k-1}}{a_{k-1}} * \ldots * C\binom{b_0}{a_0}$

####代码：
``` C++
typedef long long ll;

ll n, m, p;

ll qPow (ll a, ll k) {
	ll ans = 1;

	while (k) {
		if (k&1)
			ans = (ans * a) % p;
		a = (a * a) % p;
		k /= 2;
	}
	return ans;
}

ll C (ll a, ll b, ll p) {

	if (a < b)
		return 0;

	if (b > a - b)
		b = a - b;

	ll up = 1, down = 1;

	for (ll i = 0; i < b; i++) {
		up = up * (a-i) % p;
		down = down * (i+1) % p;
	}
	return up * qPow(down, p-2) % p; // 逆元
}

ll lucas (ll a, ll b, ll p) {
	if (b == 0)
		return 1;
	return C(a%p, b%p, p) * lucas(a/p, b/p, p) % p;
}
```