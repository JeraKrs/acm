/* 凸包 */
int getConvexHull (Point* p, int n, Point* ch) {
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		/* 可共线 */
		//while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) < 0) m--;
		while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n-2; i >= 0; i--) {
		/* 可共线 */
		//while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) < 0) m--;
		while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}
