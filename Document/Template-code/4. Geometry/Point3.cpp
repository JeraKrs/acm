#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
const double eps = 1e-8;

inline int dcmp (double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }

struct Point3 {
	double x, y, z;

	Point3 (double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
	void read () { scanf("%lf%lf%lf", &x, &y, &z); }

	bool operator < (const Point3& u) const { return dcmp(x-u.x)<0 || (dcmp(x-u.x)==0 && dcmp(y-u.y)<0) || (dcmp(x-u.x)==0 && dcmp(y-u.y)==0 && dcmp(z-u.z) < 0); }
	bool operator > (const Point3& u) const { return u < (*this); }
	bool operator == (const Point3& u) const { return !(u < (*this) || (*this) < u); }
	bool operator != (const Point3& u) const { return !((*this) == u); }
	bool operator <= (const Point3& u) const { return *this < u || *this == u; }
	bool operator >= (const Point3& u) const { return *this > u || *this == u; }
	Point3 operator + (const Point3& u) const { return Point3(x+u.x, y+u.y, z+u.z); }
	Point3 operator - (const Point3& u) const { return Point3(x-u.x, y-u.y, z-u.z); }
	Point3 operator * (const double u) const { return Point3(x*u, y*u, z*u); }
	Point3 operator / (const double u) const { return Point3(x/u, y/u, z/u); }
};

typedef Point3 Vector3;

double getDot(Vector3 a, Vector3 b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
Vector3 getCross (Vector3 a, Vector3 b) { return Vector3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x); }
double getLength(Vector3 a) { return sqrt(getDot(a, a)); }
double getAngle(Vector3 a, Vector3 b) { return acos(getDot(a, b) / getLength(a) / getLength(b)); }
Vector3 getNormal(Point3 a, Point3 b, Point3 c) {  
	Vector3 u = a-b, v = b-c;
	Vector3 k = getCross(u, v);
	return k / getLength(k);
}
double getDistancePointToPlane (Point3 p, Point3 p0, Vector3 v) { return fabs(getDot(p-p0, v)); }
Point3 getPlaneProjection (Point3 p, Point3 p0, Vector3 v) { return p - v * getDot(p-p0, v); }
