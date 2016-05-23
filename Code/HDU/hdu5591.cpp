#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main () {
	int cas, n;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		printf("%d\n", n&1);
	}
	return 0;
}
