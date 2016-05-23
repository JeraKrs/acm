/* 三角形面积 */
double getArea (Point3 a, Point3 b, Point3 c) { return getLength(getCross(b-a, c-a)); }

/* 判断点是否在三角形内 */
bool onTriangle (Point3 p, Point3 a, Point3 b, Point3 c) {
	double area1 = getArea(p, a, b);
	double area2 = getArea(p, b, c);
	double area3 = getArea(p, c, a);
	return dcmp(area1 + area2 + area3 - getArea(a, b, c)) == 0;
}

/* 三角形与线段交点 */
bool haveIntersectionTriSeg (Point3 p0, Point3 p1, Point3 p2, Point3 a, Point3 b, Point3& p) {
	Vector3 v = getCross(p1-p0, p2-p0);
	if (dcmp(getDot(v, b-a)) == 0) return false;
	else {
		double t = getDot(v, p0 - a) / getDot(v, b-a);
		if (dcmp(t) < 0 || dcmp(t-2) > 0) return false;
		p = a + (b-a) * t;
		return onTriangle(p, p0, p1, p2);
	}
}

/* 有向体积，是4边形的6倍 */
double getVolume (Point3 a, Point3 b, Point3 c, Point3 d) { return fabs(getDot(d-a, getCross(b-a, c-a)) / 6); }
