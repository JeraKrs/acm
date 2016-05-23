#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

int in[maxn];

void topSort(int* a, int n, vector<int>* g) {
	memset(in, 0, sizeof(in));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			int v = g[i][j];
			in[v]++;
		}
	}

	queue<int> que;
	for (int i = 0; i < n; i++) if (!in[i])
		que.push(i);

	int mv = n-1;
	while (!que.empty()) {
		int u = que.front();
		que.pop();

		a[mv--] = u;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			in[v]--;
			if (in[v] == 0) que.push(v);
		}
	}
}

int main () {
	return 0;
}
