#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 30;
const double eps = 1e-9;
typedef double Mat[maxn+5][maxn+5];

void gauss_elimination (Mat a, int n) {

	for (int i = 0; i < n; i++) {
		int r = i;

		for (int j = i + 1; j < n; j++) 
			if (fabs(a[j][i]) > fabs(a[r][i]))
				r = j;

		if (r != i) {
			for (int j = 0; j <= n; j++)
				swap(a[r][j], a[i][j]);
		}

		if (fabs(a[i][i]) < 1e-9)
			continue;

		for (int k = i + 1; k < n; k++) {
			double f = a[k][i] / a[i][i];
			for (int j = 0; j <= n; j++)
				a[k][j] -= a[i][j] * f;
		}
	}

	for (int i = n-1; i >= 0; i--) {
		for (int j = i+1; j < n; j++)
			a[i][n] -= a[j][j] * a[i][j];
		a[i][i] = a[i][n] / a[i][i];
		if (fabs(a[i][i]) < 1e-9)
			a[i][i] = 0;
	}
}

int main () {
	return 0;
}
