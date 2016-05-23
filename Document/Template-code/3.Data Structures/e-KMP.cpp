const int maxn = 1e5 + 5;
int cpfix[maxn], extand[maxn];

void getCPfix(char* str) {
	int n = strlen(str + 1), tmp = 1;
	cpfix[1] = n;

	while (tmp < n && str[tmp] == str[tmp+1])
		tmp++;
	cpfix[2] = tmp-1;

	int p = 2;
	for (int k = 3; k <= n; k++) {
		int e = p + cpfix[p] - 1, l = cpfix[k-p+1]; // e 为目前匹配过的最末位置, l 为对应的偏移;

		if (k + l - 1 >= e) {
			int j = e - k > 0 ? e - k : 0;
			while (k + j <= n && str[k+j] == str[j+1])
				j++;
			cpfix[k] = j, p = k;
		} else
			cpfix[k] = l;
	}
	/*
	for (int i = 1; i <= n; i++)
		printf("%d%c", cpfix[i], i == n ? '\n' : ' ');
		*/
}

void getExtand(char* S, char* T) {
	getCPfix(T);

	int sn = strlen(S+1), tn = strlen(T+1);
	int n = min(sn, tn), tmp = 1;

	while (tmp <= n && S[tmp] == T[tmp])
		tmp++;
	extand[1] = tmp-1;

	int p = 1;
	for (int k = 2; k <= sn; k++) {
		int e = p + extand[p] - 1, l = cpfix[k-p+1];

		if (k + l - 1 >= e) {
			int j = e - k > 0 ? e - k : 0;
			while (k + j <= sn && j < tn && S[k+j] == T[j+1])
				j++;
			extand[k] = j, p = k;

		} else
			extand[k] = l;
	}

	/*
	for (int i = 1; i <= sn; i++) 
		printf("%d%c", extand[i], i == sn ? '\n' : ' ');
		*/
}
