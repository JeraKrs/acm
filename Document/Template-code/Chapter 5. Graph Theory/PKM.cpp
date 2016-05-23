#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;

int N, L[maxn], Lx[maxn], Ly[maxn], W[maxn][maxn], slack[maxn];
bool S[maxn], T[maxn];

int match (int u) {
    S[u] = true;
    for (int i = 1; i <= N; i++) if (!T[i]) {
        if (Lx[u] + Ly[i] == W[u][i]) {
            T[i] = true;
            if (!L[i] || match(L[i])) {
                L[i] = u;
                return true;
            }
        } else
            slack[i] = min(slack[i], Lx[u]+Ly[i]-W[u][i]);
    }
    return false;
}

void update () {
    int a = inf;
    for (int i = 1; i <= N; i++) if (!T[i])
        a = min(a, slack[i]);

    for (int i = 1; i <= N; i++) {
        if (S[i]) Lx[i] -= a;
        if (T[i]) Ly[i] += a;
    }
}

void KM () {
    for (int i = 1; i <= N; i++) {
        L[i] = Lx[i] = Ly[i] = 0;
        for (int j = 1; j <= N; j++)
            Lx[i] = max(Lx[i], W[i][j]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) slack[j] = inf;
        while (true) {
            for (int j = 1; j <= N; j++) S[j] = T[j] = false;
            if (match(i)) break;
            else update();
        }
    }
}

int main () {
    return 0;
}
