/* 空间点到直线的距离 */
double getDistancePointToLine(Point3 p, Point3 a, Point3 b) {
	Vector3 v1 = b-a, v2 = p-a;
	return getLength(getCross(v1,v2)) / getLength(v1);
}

/* 空间点到线段的距离 */
double getDistancePointToSegment(Point3 p, Point3 a, Point3 b) {
	if (a == b) return getLength(p-a);
	Vector3 v1 = b-a, v2 = p-a, v3 = p-b;
	if (dcmp(getDot(v1, v2)) < 0) return getLength(v2);
	else if (dcmp(getDot(v1, v3)) > 0) return getLength(v3);
	else return getLength(getCross(v1, v2)) / getLength(v1);
}

/* 异面直线公垂线 */
bool getPointLineToLine (Point3 a, Vector3 u, Point3 b, Vector3 v, double& s) {
	double p = getDot(u, u) * getDot(v, v) - getDot(u, v) * getDot(u, v);
	if (dcmp(p) == 0) return false;
	double q = getDot(u, v) * getDot(v, a-b) - getDot(v, v) * getDot(u, a-b);
	s = p/q;
	return true;
}

/* 异面直线的距离 */
double getDistanceLineToLine (Point3 a, Vector3 u, Point3 b, Vector3 v) {
	Vector3 p = getCross(u, v);
	return fabs(getDot(p, (a-b)) / getLength(p));
}

/* 异面线段距离 */
double getDistanceSegmentToSegment(Point3 a, Point3 b, Point3 c, Point3 d) {
	double s, t;
	bool flag1 = getPointLineToLine(a, b-a, c, d-c, s);
	bool flag2 = getPointLineToLine(c, d-c, a, b-a, t);
	if (flag1 && flag2 && dcmp(s) > 0 && dcmp(s - 1) < 0 && dcmp(t) > 0 && dcmp(t-1) < 0) {
		Vector3 u = b-a, v = d-c;
		Point3 p = a + u * s, q = b + v * t;
		return getLength(p-q);
	} else {
		double ans = 1e20;
		ans = min(ans, getDistancePointToSegment(a, c, d));
		ans = min(ans, getDistancePointToSegment(b, c, d));
		ans = min(ans, getDistancePointToSegment(c, a, b));
		ans = min(ans, getDistancePointToSegment(d, a, b));
		return ans;
	}
}
