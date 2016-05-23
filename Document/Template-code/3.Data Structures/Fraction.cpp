#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long type;

struct Fraction {
	type mem; // 分子；
	type den; // 分母；

	bool operator < (const Fraction& u) const;
	bool operator > (const Fraction& u) const { return u < *this; }
	bool operator <= (const Fraction& u) const { return !(u < *this); }
	bool operator >= (const Fraction& u) const { return !(*this < u); }
	bool operator != (const Fraction& u) const { return u < *this || *this > u; }
	bool operator == (const Fraction& u) const { return !(u != *this); }
	Fraction (type mem = 0, type den = 1);
	void operator = (type x) { this->set(x, 1); }
	Fraction operator * (const Fraction& u);
	Fraction operator / (const Fraction& u);
	Fraction operator + (const Fraction& u);
	Fraction operator - (const Fraction& u);

	void set(type mem, type den);
	void put () {
		if (mem == 0) {
			printf("0");
		} else {
			printf("%lld", mem);
			if (den != 1)
				printf("/%lld", den);
		}
		printf(" ");
	}
};

inline type gcd (type a, type b) {
	return b == 0 ? (a > 0 ? a : -a) : gcd(b, a % b);
}

inline type lcm (type a, type b) {
	return a / gcd(a, b) * b;
}

/***** Code ******/


bool Fraction::operator < (const Fraction& u) const {
	return mem * u.den < u.mem * den;
}

Fraction::Fraction (type mem, type den) {
	this->set(mem, den);
}

Fraction Fraction::operator * (const Fraction& u) {
	type tmp_p = gcd(mem, u.den);
	type tmp_q = gcd(u.mem, den);
	return Fraction( (mem / tmp_p) * (u.mem / tmp_q), (den / tmp_q) * (u.den / tmp_p) );
}

Fraction Fraction::operator / (const Fraction& u) {
	type tmp_p = gcd(mem, u.mem);
	type tmp_q = gcd(den, u.den);
	return Fraction( (mem / tmp_p) * (u.den / tmp_q), (den / tmp_q) * (u.mem / tmp_p));
}

Fraction Fraction::operator + (const Fraction& u) {
	type tmp_l = lcm (den, u.den);
	return Fraction(tmp_l / den * mem + tmp_l / u.den * u.mem, tmp_l);
}

Fraction Fraction::operator - (const Fraction& u) {
	type tmp_l = lcm (den, u.den);
	return Fraction(tmp_l / den * mem - tmp_l / u.den * u.mem, tmp_l);
}

void Fraction::set (type mem, type den) {

	if (den == 0) {
		den = 1;
		mem = 0;
	}

	type tmp_d = gcd(mem, den);
	this->mem = mem / tmp_d;
	this->den = den / tmp_d;
}
