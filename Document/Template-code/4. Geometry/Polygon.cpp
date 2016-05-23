/* 余弦定理: 三边确定一角 */
double getAngle (double a, double b, double c) { return acos((a*a+b*b-c*c) / (2*a*b)); }
double getArea (double a, double b, double c) { double s =(a+b+c)/2; return sqrt(s*(s-a)*(s-b)*(s-c)); }
double getArea (double a, double h) { return a * h / 2; }
double getArea (Point a, Point b, Point c) { return fabs(getCross(b - a, c - a)) / 2; }
double getDirArea (Point a, Point b, Point c) { return getCross(b - a, c - a) / 2; }

typedef vector<Point> Polygon;

double getPolygonalgetArea (Point* p, int n) {
	double ret = 0;
	for (int i = 0; i < n-1; i++)
		ret += (p[i]-p[0]) ^ (p[i+1]-p[0]);
	return ret/2;
}

int isPointInPolygon (Point o, Point* p, int n) {
	int wn = 0;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		if (onSegment(o, p[i], p[j]) || o == p[i]) return 0; // 边界上
		int k = dcmp(getCross(p[j] - p[i], o-p[i]));
		int d1 = dcmp(p[i].y - o.y);
		int d2 = dcmp(p[j].y - o.y);
		if (k > 0 && d1 <= 0 && d2 > 0) wn++;
		if (k < 0 && d2 <= 0 && d1 > 0) wn--;
	}
	return wn ? -1 : 1;
}

/* 去除多边形共线点 */
Polygon simplify (const Polygon& poly) {
	Polygon ret;
	int n = poly.size();
	for (int i = 0; i < n; i++) {
		Point a = poly[i];
		Point b = poly[(i+1)%n];
		Point c = poly[(i+2)%n];
		if (dcmp((b-a)^(c-b)) != 0 && (ret.size() == 0 || b != ret[ret.size()-1]))
			ret.push_back(b);
	}
	return ret;
}

/* 计算半平面相交可以用增量法，o(n^2)，初始设置4条无穷大的半平面 */
/* 用有向直线A->B切割多边形u，返回左侧。可能退化成单点或线段 */
Polygon cutPolygon (Polygon u, Point a, Point b) {
	Polygon ret;
	int n = u.size();
	for (int i = 0; i < n; i++) {
		Point c = u[i], d = u[(i+1)%n];
		if (dcmp((b-a)^(c-a)) >= 0) ret.push_back(c);
		if (dcmp((b-a)^(c-d)) != 0) {
			Point t;
			getIntersection(a, b-a, c, d-c, t);
			if (onSegment(t, c, d))
				ret.push_back(t);
		}
	}
	return ret;
}
