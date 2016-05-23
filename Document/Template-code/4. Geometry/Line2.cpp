struct Line {
	double a, b, c;
	Line (double a = 0, double b = 0, double c = 0): a(a), b(b), c(c) {}
};

Line getLine (double x1, double y1, double x2, double y2) { return Line(y2-y1, x1-x2, y1*x2-x1*y2); }
Line getLine (double a, double b, Point u) { return Line(a, -b, u.y * b - u.x * a); }

bool getIntersection (Line p, Line q, Point& o) {
	if (fabs(p.a * q.b - q.a * p.b) < eps)
		return false;
	o.x = (q.c * p.b - p.c * q.b) / (p.a * q.b - q.a * p.b);
	o.y = (q.c * p.a - p.c * q.a) / (p.b * q.a - q.b * p.a);
	return true;
}


/* 直线pv和直线qw的交点 */
bool getIntersection (Point p, Vector v, Point q, Vector w, Point& o) {
	if (dcmp(getCross(v, w)) == 0) return false;
	Vector u = p - q;
	double k = getCross(w, u) / getCross(v, w);
	o = p + v * k;
	return true;
}

/* 点p到直线ab的距离 */
double getDistanceToLine (Point p, Point a, Point b) { return fabs(getCross(b-a, p-a) / getLength(b-a)); }

/* 点p到线段ab的距离 */
double getDistanceToSegment (Point p, Point a, Point b) {
	if (a == b) return getLength(p-a);
	Vector v1 = b - a, v2 = p - a, v3 = p - b;
	if (dcmp(getDot(v1, v2)) < 0) return getLength(v2);
	else if (dcmp(getDot(v1, v3)) > 0) return getLength(v3);
	else return fabs(getCross(v1, v2) / getLength(v1));
}

/* 点p在直线ab上的投影 */
Point getPointToLine (Point p, Point a, Point b) {
	Vector v = b-a; 
	return a+v*(getDot(v, p-a) / getDot(v,v));
}

/* 判断线段是否存在交点 */
bool haveIntersection (Point a1, Point a2, Point b1, Point b2) {
	double c1=getCross(a2-a1, b1-a1), c2=getCross(a2-a1, b2-a1), c3=getCross(b2-b1, a1-b1), c4=getCross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}

/* 判断点是否在线段上 */
bool onSegment (Point p, Point a, Point b) { return dcmp(getCross(a-p, b-p)) == 0 && dcmp(getDot(a-p, b-p)) < 0; }
