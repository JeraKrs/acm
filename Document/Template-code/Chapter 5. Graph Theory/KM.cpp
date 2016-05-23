#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

int N, L[maxn];
bool T[maxn];
vector<int> G[maxn];

bool match(int u) {
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!T[v]) {
            T[v] = true;
            if (!L[v] || match(L[v])) {
                L[v] = u;
                return true;
            }
        }
    }
    return false;
}

int KM () {
    int ret = 0;
    memset(L, 0, sizeof(L));
    for (int i = 1; i <= N; i++) {
        memset(T, false, sizeof(T));
        if (match(i)) ret++;
    }
    return ret;
}

int main () {
	return 0;
}
