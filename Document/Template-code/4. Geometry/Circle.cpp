struct Circle {
	Point o;
	double r;
	Circle () {}
	Circle (Point o, double r = 0): o(o), r(r) {}
	void read () { o.read(), scanf("%lf", &r); }
	Point point(double rad) { return Point(o.x + cos(rad)*r, o.y + sin(rad)*r); }
	double getArea (double rad) { return rad * r * r / 2; }
};

/* 直线和圆的交点 */
int getLineCircleIntersection (Point p, Point q, Circle O, double& t1, double& t2, vector<Point>& sol) {
	Vector v = q - p;
	/* 使用前需清空sol */
	//sol.clear();
	double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
	double e = a*a+c*c, f = 2*(a*b+c*d), g = b*b+d*d-O.r*O.r;
	double delta = f*f - 4*e*g;
	if (dcmp(delta) < 0) return 0;
	if (dcmp(delta) == 0) {
		t1 = t2 = -f / (2 * e);
		sol.push_back(p + v * t1);
		return 1;
	}

	t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(p + v * t1);
	t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(p + v * t2);
	return 2;
}

/* 圆和圆的交点 */
int getCircleCircleIntersection (Circle o1, Circle o2, vector<Point>& sol) {
	double d = getLength(o1.o - o2.o);

	if (dcmp(d) == 0) {
		if (dcmp(o1.r - o2.r) == 0) return -1;
		return 0;
	}

	if (dcmp(o1.r + o2.r - d) < 0) return 0;
	if (dcmp(fabs(o1.r-o2.r) - d) > 0) return 0;

	double a = getAngle(o2.o - o1.o);
	double da = acos((o1.r*o1.r + d*d - o2.r*o2.r) / (2*o1.r*d));

	Point p1 = o1.point(a-da), p2 = o1.point(a+da);

	sol.push_back(p1);
	if (p1 == p2) return 1;
	sol.push_back(p2);
	return 2;
}

/* 三点确定内切圆 */
Circle InscribedCircle(Point p1, Point p2, Point p3) {  
	double a = getLength(p2 - p3);  
	double b = getLength(p3 - p1);  
	double c = getLength(p1 - p2);  
	Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);  
	return Circle(p, getDistanceToLine(p, p1, p2));  
}

/* 三点确定外切圆 */
Circle CircumscribedCircle(Point p1, Point p2, Point p3) {  
	double Bx = p2.x - p1.x, By = p2.y - p1.y;  
	double Cx = p3.x - p1.x, Cy = p3.y - p1.y;  
	double D = 2 * (Bx * Cy - By * Cx);  
	double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;  
	double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;  
	Point p = Point(cx, cy);  
	return Circle(p, getLength(p1 - p));  
}

/* 过定点作圆的切线 */
int getTangentsPointToCircle (Point p, Circle o, Vector* v) {
	Vector u = o.o - p;
	double d = getLength(u);
	if (d < o.r) return 0;
	else if (dcmp(d - o.r) == 0) {
		v[0] = rotate(u, pi / 2);
		return 1;
	} else {
		double ang = asin(o.r / d);
		v[0] = rotate(u, -ang);
		v[1] = rotate(u, ang);
		return 2;
	}
}

/* a[i] 和 b[i] 分别是第i条切线在O1和O2上的切点 */
/* have some problems */
int getTangentsCircleToCircle (Circle o1, Circle o2, Point* a, Point* b) {
	int cnt = 0;
	if (o1.r < o2.r) { swap(o1, o2); swap(a, b); }
	double d2 = getLength(o1.o - o2.o); d2 = d2 * d2;
	double rdif = o1.r - o2.r, rsum = o1.r + o2.r;
	if (d2 < rdif * rdif) return 0;
	if (dcmp(d2) == 0 && dcmp(o1.r - o2.r) == 0) return -1;

	double base = getAngle(o2.o - o1.o);
	if (dcmp(d2 - rdif * rdif) == 0) {
		a[cnt] = o1.point(base); b[cnt] = o2.point(base); cnt++;
		return cnt;
	}

	double ang = acos( rdif / sqrt(d2) );
	a[cnt] = o1.point(base+ang); b[cnt] = o2.point(base+ang); cnt++;
	a[cnt] = o1.point(base-ang); b[cnt] = o2.point(base-ang); cnt++;

	if (dcmp(d2 - rsum * rsum) == 0) {
		a[cnt] = o1.point(base); b[cnt] = o2.point(base); cnt++;
	} else if (d2 > rsum * rsum) {
		double ang = acos( rsum / sqrt(d2) );
		a[cnt] = o1.point(base+ang); b[cnt] = o2.point(pi+base+ang); cnt++;
		a[cnt] = o1.point(base-ang); b[cnt] = o2.point(pi+base-ang); cnt++;
	}
	return cnt;
}

/* 获得点与圆的切点 */
void getTangPointsPointToCircle(Point p, Circle c, Point& a, Point& b) {
	double k = 2 * (c.r*c.r + c.o.x*p.x + c.o.y*p.y - c.o.x*c.o.x - c.o.y*c.o.y);
	double s = 2 * (p.x-c.o.x), t = 2 * (p.y - c.o.y);

	if (dcmp(t) == 0) {
		a.x = b.x = k / s;
		double tmp = sqrt(c.r * c.r - (c.o.x-a.x)*(c.o.x-a.x));
		a.y = c.o.y + tmp;
		b.y = c.o.y - tmp;
	} else {
		double x = c.o.y - k/t;
		double A = 1 + (s/t) * (s/t);
		double B = 2 * (x*s/t - c.o.x);
		double C = c.o.x * c.o.x + x * x - c.r * c.r;
		double tmp = sqrt(B * B - 4 * A * C);
		a.x = (tmp - B) / 2 / A;
		b.x = (-tmp - B) / 2 / A;
		a.y = (k - s * a.x) / t;
		b.y = (k - s * b.x) / t;
	}
}

/* 圆与圆的切点 */
void getTangPointsCircleToCircle (Circle c1, Circle c2, Point& a, Point& b) {
	double x0 = c2.o.x - c1.o.x, y0 = c2.o.y - c1.o.y, cs, sn, rdis = c1.r - c2.r;

	if (dcmp(y0) == 0) {
		cs = rdis / x0;
		sn = sqrt(1 - cs * cs);
		a = Point(c1.r * cs + c1.o.x, c1.r * sn + c1.o.y);
		b = Point(c1.r * cs + c1.o.x, c1.r * (-sn) + c1.o.y);
	} else {
		double A = (x0/y0)*(x0/y0) + 1;
		double B = -2 * x0 * rdis / y0 / y0;
		double C = (rdis / y0) * (rdis / y0) - 1;
		double delta = sqrt(B * B - 4 * A * C);
		cs = (-B + delta) / 2 / A;
		sn = (rdis - x0 * cs) / y0;
		a = Point(c1.r * cs + c1.o.x, c1.r * sn + c1.o.y);

		cs = (-B - delta) / 2 / A;
		sn = (rdis - x0 * cs) / y0;
		b = Point(c1.r * cs + c1.o.x, c1.r * sn + c1.o.y);
	}
}
