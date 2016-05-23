
namespace ComplexVector {
	typedef complex<double> Point;
	typedef Point Vector;

	double getDot(Vector a, Vector b) { return real(conj(a)*b); }
	double getCross(Vector a, Vector b) { return imag(conj(a)*b); }
	Vector rotate(Vector a, double rad) { return a*exp(Point(0, rad)); }
};


/* 旋转卡壳 */
void rotatingCalipers(Point *p, int n, vector<pii>& sol) {
	sol.clear();
	int j = 1; p[n] = p[0];
	for (int i = 0; i < n; i++) {
		while (getCross(p[j+1]-p[i+1], p[i]-p[i+1]) > getCross(p[j]-p[i+1], p[i]-p[i+1]))
			j = (j+1) % n;
		sol.push_back(make_pair(i, j));
		sol.push_back(make_pair(i + 1, j + 1));
	}
}

void rotatingCalipersGetRectangle (Point *p, int n, double& area, double& perimeter) {
	p[n] = p[0];
	int l = 1, r = 1, j = 1;
	area = perimeter = 1e20;

	for (int i = 0; i < n; i++) {
		Vector v = (p[i+1]-p[i]) / getLength(p[i+1]-p[i]);
		while (dcmp(getDot(v, p[r%n]-p[i]) - getDot(v, p[(r+1)%n]-p[i])) < 0) r++;
		while (j < r || dcmp(getCross(v, p[j%n]-p[i]) - getCross(v,p[(j+1)%n]-p[i])) < 0) j++;
		while (l < j || dcmp(getDot(v, p[l%n]-p[i]) - getDot(v, p[(l+1)%n]-p[i])) > 0) l++;
		double w = getDot(v, p[r%n]-p[i])-getDot(v, p[l%n]-p[i]);
		double h = getDistanceToLine (p[j%n], p[i], p[i+1]);
		area = min(area, w * h);
		perimeter = min(perimeter, 2 * w + 2 * h);
	}
}

