#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main () {
	int n, m, s, cas;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d%d", &n, &m);
		int c = n + m - 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &s);
				if (s) c++;
			}
		}
		printf("%s\n", c&1 ? "NO" : "YES");
	}
	return 0;
}
