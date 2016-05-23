/**********************
 * 牛顿插值法
 * 给出一个序列的n项，求满足序列规律的后c项，要求尽量小
 *
 * 每次求两项之间的差，形成一个新的序列，直到序列公差为0时，回带回原来的序列
 **********************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 205;

int S, C, arr[maxn][maxn];

int main () {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d%d", &S, &C);
		for (int i = 0; i < S; i++)
			scanf("%d", &arr[0][i]);

		for (int i = 1; i < S; i++) {
			for (int j = 0; j < S - i; j++)
				arr[i][j] = arr[i-1][j+1] - arr[i-1][j];
		}

		for (int i = 1; i <= C; i++)
			arr[S-1][i] = arr[S-1][0];

		for (int i = S-2; i >= 0; i--) {
			int pos = S - i;
			for (int j = 0; j < C; j++)
				arr[i][j+pos] = arr[i+1][j+pos-1] + arr[i][j+pos-1];
		}

		printf("%d", arr[0][S]);
		for (int i = 1; i < C; i++)
			printf(" %d", arr[0][S+i]);
		printf("\n");
	}
	return 0;
}
