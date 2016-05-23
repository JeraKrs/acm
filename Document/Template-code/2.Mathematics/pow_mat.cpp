#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 105;
const int mod = 1e9 + 7;

struct Mat {
    int r, c, s[maxn][maxn];

    void init(int r, int c) {
        this->r = r;
        this->c = c;
        memset(s, 0, sizeof(s));
    }
}tmp;

void mul(const Mat& a, const Mat& b, Mat& c) {
    tmp.init(a.r, b.c);
    for (int i = 0; i < tmp.r; i++) {
        for (int j = 0; j < tmp.c; j++)
            for (int k = 0; k < a.c; k++)
                tmp.s[i][j] = (tmp.s[i][j] + 1LL * a.s[i][k] * b.s[k][j] % mod) % mod;
    }
    c = tmp;
}

Mat pow_mat(Mat ret, Mat x, int n) {

    while (n) {
        if (n&1) mul(x, ret, ret);
        mul(x, x, x);
        n >>= 1;
    }
	return ret;
}

int main () {
    return 0; 
}
