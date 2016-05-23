struct DirLine {
	Point p;
	Vector v;
	double ang;
	DirLine () {}
	DirLine (Point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }
	bool operator < (const DirLine& u) const { return ang < u.ang; }
};
bool onLeft(DirLine l, Point p) { return dcmp(l.v ^ (p-l.p)) >= 0; }

/* 半平面相交 */
int halfPlaneIntersection(DirLine* li, int n, Point* poly) {
	sort(li, li + n);

	int first, last;
	Point* p = new Point[n];
	DirLine* q = new DirLine[n];
	q[first=last=0] = li[0];

	for (int i = 1; i < n; i++) {
		while (first < last && !onLeft(li[i], p[last-1])) last--;
		while (first < last && !onLeft(li[i], p[first])) first++;
		q[++last] = li[i];

		if (dcmp(q[last].v ^ q[last-1].v) == 0) {
			last--;
			if (onLeft(q[last], li[i].p)) q[last] = li[i];
		}

		if (first < last)
			getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);
	}

	while (first < last && !onLeft(q[first], p[last-1])) last--;
	if (last - first <= 1) { delete [] p; delete [] q; return 0; }
	getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);

	int m = 0;
	for (int i = first; i <= last; i++) poly[m++] = p[i];
	delete [] p; delete [] q;
	return m;
}

