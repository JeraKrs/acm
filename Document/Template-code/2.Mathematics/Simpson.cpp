#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

double F(double x) { return x; }

double simpson(double a, double b) {
	double c = (b + a) / 2;
	return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;
}

double asr(double a, double b, double ep, double A) {
	double c = (a + b) / 2;
	double L = simpson(a, c), R = simpson(c, b);
	if (fabs(L + R - A) <= 15 * ep) return L + R + (L + R - A) / 15;
	return asr(a, c, ep/2, L) + asr(c, b, ep/2, R);
}

double asr(double a, double b, double ep) {
	return asr(a, b, ep, simpson(a, b));
}

int main () {
	return 0;
}
