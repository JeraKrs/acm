#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5;
const int maxr = 20;

// 一维
int d[maxn][maxr];

void rmq_init (const vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; i++)
		d[i][0] = arr[i];

	for (int j = 1; (1<<j) <= n; j++) {
		for (int i = 0; i + (1<<j) - 1 < n; i++)
			d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
	}
}

int rmq_query (int l, int r) {
	int k = 0;
	while ((1<<(k+1)) <= r - l + 1)
		k++;
	return min(d[l][k], d[r-(1<<k)+1][k]);
}

// 二维

int N, M, Q, g[maxn][maxn], dp[maxn][maxn][9][9];

void rmq_init(int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			dp[i][j][0][0] = g[i][j];
	}

	for (int x = 0; (1<<x) <= n; x++)
		for (int y = 0; (1<<y) <= m; y++)
			if (x + y)
				for (int i = 1; i + (1<<x) - 1 <= n; i++)
					for (int j = 1; j + (1<<y) - 1 <= m; j++) {
						if (x)
							dp[i][j][x][y] = max(dp[i][j][x-1][y], dp[i+(1<<(x-1))][j][x-1][y]);
						else
							dp[i][j][x][y] = max(dp[i][j][x][y-1], dp[i][j+(1<<(y-1))][x][y-1]);
					}
}

int rmq_query(int x1, int y1, int x2, int y2) {
	int x = 0, y = 0;
	while ((1<<(x+1)) <= x2 - x1 + 1) x++;
	while ((1<<(y+1)) <= y2 - y1 + 1) y++;
	x2 = x2 - (1<<x) + 1;
	y2 = y2 - (1<<y) + 1;

	return max( max(dp[x1][y1][x][y], dp[x2][y1][x][y]), max(dp[x1][y2][x][y], dp[x2][y2][x][y]));
}
