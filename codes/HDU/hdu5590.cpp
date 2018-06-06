#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 105;

bool judge (char a, char b) {
	if (a == 'A' && b == 'U') return true;
	if (a == 'C' && b == 'G') return true;
	if (a == 'G' && b == 'C') return true;
	if (a == 'T' && b == 'A') return true;
	return false;
}

int main () {
	int cas, n;
	scanf("%d", &cas);
	while (cas--) {
		char dna[maxn], rna[maxn];
		scanf("%d%s%s", &n, dna, rna);
		bool flag = true;
		for (int i = 0; i < n; i++) flag &= judge(dna[i], rna[i]);
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
