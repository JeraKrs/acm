int miniexpress(char* s) {
	int n = strlen(s), p = 0, q = 1;
	while (p < n && q < n) {
		int i;
		for (i = 0; i < n; i++) {
			if (s[(p+i)%n] != s[(q+i)%n])
				break;
		}

		if (s[(p+i)%n] > s[(q+i)%n])
			p = p + i + 1;
		else
			q = q + i + 1;

		if (p == q)
			q++;
	}
	return min(p, q) + 1;;
}