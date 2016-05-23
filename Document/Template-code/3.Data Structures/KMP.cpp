const int maxn = 1e5 + 5;
int fail[maxn];

void getFail (char* str) {
	int n = strlen(str+1);
    int p = fail[0] = fail[1] = 0;

    for (int i = 2; i <= n; i++) {
        while (p && str[p+1] != str[i])
            p = fail[p];

        if (str[p+1] == str[i])
            p++;
        fail[i] = p;
    }

	/*
	for (int i = 1; i <= n; i++)
		printf("%d%c", fail[i], i == n ? '\n' : ' ');
		*/
}

int match (char* S, char* T) {
	getFail(T);

    int p = 0, ret = 0, n = strlen(S);
    for (int i = 1; i <= n; i++) {
        while (p && T[p+1] != S[i])
            p = fail[p];

        if (T[p+1] == S[i])
            p++;

        ret = max(ret, p);
    }
    return ret;
}
