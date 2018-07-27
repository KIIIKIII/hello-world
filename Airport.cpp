#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 10000 + 5;
const int INF = 0x3f3f3f3f3f;
const double eps = 1e-6;
int dcmp(double x) { if (fabs(x) < eps) return 0; return (x < 0) ? -1 : 1; }
typedef struct Point {
	double x, y;
	Point(double _x = 0, double _y = 0) :x(_x), y(_y) {};
}Vector;
Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
Point operator*(Point A, double p) { return Point(A.x * p, A.y * p); }
Point operator/(Point A, double p) { return Point(A.x / p, A.y / p); }
Point read_point() { double x, y; scanf("%lf%lf", &x, &y); return Point(x, y); }
bool operator<(const Point&a, const Point&b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
bool operator==(const Point&a, const Point&b) { return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0; }
double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
double Length(Point A) { return sqrt(Dot(A, A)); }
double Angle(Point A, Point B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Angle(Point v) { return atan2(v.y, v.x); }
double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
Point Horunit(Point x) { return x / Length(x); }
Point Verunit(Point x) { return Point(-x.y, x.x) / Length(x); }
Point Rotate(Point A, double rad) { return Point(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad)); }
double Area2(const Point A, const Point B, const Point C) { return Cross(B - A, C - A); }
void getLineGeneralEquation(const Point& p1, const Point& p2, double& a, double &b, double &c) {
	a = p2.y - p1.y;
	b = p1.x - p2.x;
	c = -a * p1.x - b * p1.y;
}
Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
	Point u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v * t;
}
double DistanceToLine(Point P, Point A, Point B) {
	Point v1 = B - A, v2 = P - A;
	return fabs(Cross(v1, v2)) / Length(v1);
}
double DistanceToSegment(Point P, Point A, Point B) {
	if (A == B) return Length(P - A);
	Point v1 = B - A, v2 = P - A, v3 = P - B;
	if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
	else if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
	else return fabs(Cross(v1, v2)) / Length(v1);
}
Point GetLineProjection(Point P, Point A, Point B) {
	Point v = B - A;
	return A + v * (Dot(v, P - A) / Dot(v, v));
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1);
	double c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}
bool OnSegment(Point p, Point a1, Point a2) {
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}
double PolygonArea(Point* p, int n) {
	double area = 0;
	for (int i = 1; i < n - 1; i++)
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	return area / 2;
}
struct Line {
	Point p;
	Point v;
	double ang;
	Line(Point _p, Point _v) :p(_p), v(_v) { ang = atan2(v.y, v.x); }
	Point point(double a) { return p + (v*a); }
	bool operator<(const Line& L)const { return ang < L.ang; }
};
Line LineTransHor(Line l, int d) {
	Point vl = Verunit(l.v);
	Point p1 = l.p + vl * d, p2 = l.p - vl * d;
	Line ll = Line(p1, l.v);
	return ll;
}
Point GetLineIntersection(Line a, Line b) { return GetLineIntersection(a.p, a.v, b.p, b.v); }
bool OnLeft(const Line& L, const Point& p) { return Cross(L.v, p - L.p) >= 0; }
const double pi = acos(-1.0);
struct Circle {
	Point c;
	double r;
	Circle(Point _c = 0, double _r = 0) :c(_c), r(_r) {}
	Point point(double a) { return Point(c.x + cos(a)*r, c.y + sin(a)*r); }
};
double D(Point a, Point b, Circle C) {
	double ang1, ang2;
	Point v1, v2;
	v1 = a - C.c; v2 = b - C.c;
	ang1 = atan2(v1.y, v1.x);
	ang2 = atan2(v2.y, v2.x);
	if (ang2 < ang1) ang2 += 2 * pi;
	return C.r*(ang2 - ang1);
}
int getLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol) {
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
	double e = a * a + c * c, f = 2 * (a*b + c * d), g = b * b + d * d - C.r*C.r;
	double delta = f * f - 4.*e*g;
	if (dcmp(delta) < 0) return 0;
	if (dcmp(delta) == 0) {
		t1 = t2 = -f / (2.*e); sol.push_back(L.point(t1));
		return 1;
	}
	t1 = (-f - sqrt(delta)) / (2.*e); sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2.*e); sol.push_back(L.point(t2));
	return 2;
}
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& Sol) {
	double d = Length(C1.c - C2.c);
	if (dcmp(d) == 0) {
		if (dcmp(C1.r - C2.r) == 0) return -1;
		return 0;
	}
	if (dcmp(C1.r + C2.r - d) < 0) return 0;
	if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;
	double a = Angle(C2.c - C1.c);
	double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
	Point p1 = C1.point(a - da), p2 = C1.point(a + da);
	Sol.push_back(p1);
	if (p1 == p2) return 1;
	Sol.push_back(p2);
	return 2;
}
int getTangents(Point p, Circle C, Point* v) {
	Point u = C.c - p;
	double dist = Length(u);
	if (dist < C.r) return 0;
	else if (dcmp(dist - C.r) == 0) {
		v[0] = Rotate(u, pi / 2);
		return 1;
	}
	else {
		double ang = asin(C.r / dist);
		v[0] = Rotate(u, -ang);
		v[1] = Rotate(u, ang);
		return 2;
	}
}
int getTengents(Circle A, Circle B, Point* a, Point* b)
{
	int cnt = 0;
	if (A.r < B.r) { swap(A, B); swap(a, b); }
	int d2 = (A.c.x - B.c.x)*(A.c.x - B.c.x) + (A.c.y - B.c.y)*(A.c.y - B.c.y);
	int rdiff = A.r - B.r;
	int rsum = A.r + B.r;
	if (d2 < rdiff*rdiff) return 0;///内含

	double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
	if (d2 == 0 && A.r == B.r) return -1; ///无穷多
	if (d2 == rdiff * rdiff)//内切 1条
	{
		a[cnt] = A.point(base); b[cnt] = B.point(base); cnt++;
		return 1;
	}
	///外切
	double ang = acos((A.r - B.r) / sqrt(d2));
	a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
	a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
	if (d2 == rsum * rsum)// one
	{
		a[cnt] = A.point(base); b[cnt] = B.point(pi + base); cnt++;
	}
	else if (d2 > rsum*rsum)// two
	{
		double ang = acos((A.r - B.r) / sqrt(d2));
		a[cnt] = A.point(base + ang); b[cnt] = B.point(pi + base + ang); cnt++;
		a[cnt] = A.point(base - ang); b[cnt] = B.point(pi + base - ang); cnt++;
	}
	return cnt;
}
Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
	double Bx = p2.x - p1.x, By = p2.y - p1.y;
	double Cx = p3.x - p1.x, Cy = p3.y - p1.y;
	double D = 2 * (Bx*Cy - By * Cx);
	double cx = (Cy*(Bx*Bx + By * By) - By * (Cx*Cx + Cy * Cy)) / D + p1.x;
	double cy = (Bx*(Cx*Cx + Cy * Cy) - Cx * (Bx*Bx + By * By)) / D + p1.y;
	Point p = Point(cx, cy);
	return Circle(p, Length(p1 - p));
}
Circle InscribedCircle(Point p1, Point p2, Point p3) {
	double a = Length(p2 - p3);
	double b = Length(p3 - p1);
	double c = Length(p1 - p2);
	Point p = (p1*a + p2 * b + p3 * c) / (a + b + c);
	return Circle(p, DistanceToLine(p, p1, p2));
}
double RtoDegree(double x) { return x / pi * 180.0; }
int ConvexHull(Point *p, int n, Point *ch) {
	sort(p, p + n);
	int m = 0; 
	for (int i = 0; i < n; i++) {
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}
double torad(double deg) { return deg / 180 * pi; }


int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, m;
		Point p[MAX] = { 0 }, ch[MAX] = { 0 };
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			p[i] = read_point();
		if (n == 2 || n == 1) {
			printf("Case #%d: 0.000\n", t);
			continue;
		}
		m = ConvexHull(p, n, ch);
		double ans = INF;
		ch[m + 1] = ch[1];
		for (int i = 1; i <= m; i++) {
			double temp = 0;
			double dist = Length(ch[i] - ch[i + 1]);
			for (int j = 0; j < n; j++) {
				temp += Cross(ch[i] - p[j], ch[i + 1] - p[j]) / dist;
			}
			ans = min(ans, temp);
		}

		printf("Case #%d: %.3lf\n", t, (double)ans / (double)n);
	}

	return 0;
}
