#include "Point2.cpp"
#include "Line2.cpp"
#include "Polygon.cpp"
#include "Circle.cpp"

/* 圆与圆面积交 */
double getPublicAreaCircleToCircle(Circle a, Circle b) {
	double dis = getLength(a.o - b.o);

	if (dcmp(dis-a.r-b.r) >= 0) return 0;

	if (dis <= fabs(a.r - b.r)) { return min(a.getArea(2*pi), b.getArea(2*pi)); }

	double ang1 = getAngle(a.r, dis, b.r);
	double ang2 = getAngle(b.r, dis, a.r);
	double ret = ang1 * a.r * a.r + ang2 * b.r * b.r - dis * a.r * sin(ang1);
	return ret;
}

/* 三角形一顶点为圆心 */
double getPublicAreaCircleToTriangle (Circle O, Point a, Point b) {
	if (dcmp((a-O.o)^(b-O.o)) == 0) return 0;
	int sig = 1;
	double da = getPowLength(O.o-a), db = getPowLength(O.o-b);
	if (dcmp(da-db) > 0) {
		swap(da, db);
		swap(a, b);
		sig = -1;
	}

	double t1, t2;
	vector<Point> sol;
	int n = getLineCircleIntersection(a, b, O, t1, t2, sol);

	if (dcmp(da-O.r*O.r) <= 0) {
		if (dcmp(db-O.r*O.r) <= 0)	return getDirArea(O.o, a, b) * sig;

		int k = 0;
		if (getPowLength(sol[0]-b) > getPowLength(sol[1]-b)) k = 1;

		double ret = getArea(O.o, a, sol[k]) + O.getArea(getAngle(sol[k]-O.o, b-O.o));
		double tmp = (a-O.o)^(b-O.o);
		return ret * sig * dcmp(tmp);
	}

	double d = getDistanceToSegment(O.o, a, b);
	if (dcmp(d-O.r) >= 0) {
		double ret = O.getArea(getAngle(a-O.o, b-O.o));
		double tmp = (a-O.o)^(b-O.o);
		return ret * sig * dcmp(tmp);
	}


	double k1 = O.r / getLength(a - O.o), k2 = O.r / getLength(b - O.o);
	Point p = O.o + (a - O.o) * k1, q = O.o + (b - O.o) * k2;
	double ret1 = O.getArea(getAngle(p-O.o, q-O.o));
	double ret2 = O.getArea(getAngle(sol[0]-O.o, sol[1]-O.o)) - getArea(O.o, sol[0], sol[1]);
	double ret = (ret1 - ret2), tmp = (a-O.o)^(b-O.o);
	return ret * sig * dcmp(tmp);
}

/* 多边形和圆的面积交 */
double getPublicAreaCircleToPolygon (Circle O, Point* p, int n) {
	if (dcmp(O.r) == 0) return 0;
	double area = 0;
	for (int i = 0; i < n; i++) {
		int u = (i + 1) % n;
		area += getPublicAreaCircleToTriangle(O, p[i], p[u]);
	}
	return fabs(area);
}

int main () {
	return 0;
}
