#include <bits/stdc++.h>
#include <vector>

using namespace std;

const double EPS = 1e-9;

double DEG2RAD(double d) { return d * M_PI / 180.0; }
double RAD2DEG(double r) { return r * 180.0 / M_PI; }

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y): x(_x), y(_y){}

	double length() { return sqrt(x*x+y*y); }
	bool operator<(point n) {
		if (fabs(x - n.x) > EPS) return x < n.x;
		return y < n.y;
	}
	int normalize() {
		double l = length();
		if(fabs(l) < EPS) return -1;
		x/=l; y/=l;
		return 0;
	}
	point operator+(point a) {
		point r; r.x=x+a.x; r.y=y+a.y;
		return r;
	}
	point operator-(point a) {
		point r; r.x=x-a.x; r.y=y-a.y;
		return r;
	}
	point operator*(double sc) {
		point r; r.x=x*sc; r.y=y*sc;
		return r;
	}
};
double dist(point& a, point& b) {
	return hypot(a.x - b.x, a.y - b.y);
}
double dot(point a, point b) {
	return a.x*b.x + a.y*b.y;
}
double cross(point a, point b) {
    return a.x*b.y - a.y*b.x;
}
bool ccw(point a, point b, point c) {
    return cross(b-a, c-a) > EPS;
}
bool collinear(point a, point b, point c) {
    return fabs(cross(b-a, c-a)) < EPS;
}
void rotate(point a, point b, double theta, point &r) { // b around a CW
    b = b-a;
	r = point(b.x*cos(theta) - b.y*sin(theta),
              b.x*sin(theta) + b.y*cos(theta));
    r = r + a;
}
double angle(point a, point b, point c) { // angle aBc
    point ba = a-b;
    point bc = c-b;

    return acos(dot(ba, bc) / sqrt(dot(ba,ba)*dot(bc,bc)));
}
ostream& operator<<(ostream& os, point &p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}
void show(vector<point> &v) {
	for(point &p: v) cout << p << endl;
	cout << endl;
}

struct line {
	double a, b, c;
	line() { a = b = c = 0.0; }
	line(point p1, point p2) {
		if (fabs(p1.x-p2.x) < EPS) {
			a = 1.0;
			b = 0.0;
			c = -p1.x;
		}
		else {
			a = -(p1.y-p2.y)/(p1.x-p2.x);
			b = 1.0;
			c = -a*p1.x - p1.y;
		}
	}
	line(point p1, double m) {
		a = -m;
		b = 1.0;
		c = -(a*p1.x) + b*p1.y;
	}
};
bool are_parallel(line l1, line l2) {
	return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}
bool are_same(line l1, line l2) {
	return are_parallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}
bool are_intersect(line l1, line l2, point &p) {
    if (are_parallel(l1, l1)) return false;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    // vertical line test
    if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
    else                  p.y = -(l2.a*p.x + l2.c);
    return true;
}
double dist_to_line(point a, point p1, point p2, point &r) {
	// p1 and p2 defines the line, a is our point
	point v = p2-p1;
	v.normalize();
	double u = dot(a-p1, v);

	r = p1 + v*u;
	return dist(a, r);
}

struct seg {
    point a, b;
};
bool are_intersect(seg s1, seg s2) {
    // no check for collinear case
    if (ccw(s1.a, s1.b, s2.a) != ccw(s1.a, s1.b, s2.b) and
        ccw(s2.a, s2.b, s1.a) != ccw(s2.a, s2.b, s1.b))
        return true;

    return false;
}
double dist_to_segment(point a, point p1, point p2, point &r) {
    point v = p2-p1;
    v.normalize();
    double u = dot(a-p1, v);

    if (u < EPS){
        r = point(p1.x, p1.y);
        return dist(a, r);
    }
    if (u > dist(p1, p2)){
        r = point(p2.x, p2.y);
        return dist(a, r);
    }
    return dist_to_line(a, p1, p2, r);
}

bool circle_ptsrad(point p1, point p2, double r, point &c) {
    // to get the other center, reverse p1 and p2
    double d2 = (p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y);
    double det = r*r / d2 - 0.25;
    if (det < 0.0) return false;

    double h = sqrt(det);
    c.x = (p1.x+p2.x) * 0.5 + (p1.y-p2.y) * h;
    c.y = (p1.y+p2.y) * 0.5 + (p2.x-p1.x) * h;
    return true;
}

double perimeter(vector<point>& v) {
    int n = v.size();

    double ans = 0.0;
    for (int i=0; i<n; i++)
        ans += dist(v[i], v[i+1]);

    return ans;
}
double area(vector<point>& v) {
    int n = v.size();

    double ans = 0.0;
    for (int i=0; i<n; i++)
        ans += v[i].x*v[i+1].y - v[i+1].x*v[i].y;
        //ans += cross(v[i], v[i+1]);

    return fabs(ans)/2.0;
}
bool is_convex(vector<point> &v) {
    int n = v.size();
    if (n <= 3) return false;

    bool first_turn = ccw(v[0], v[1], v[2]);
    for (int i=1; i<n-1; i++) {
        if (ccw(v[i], v[i+1], v[(i+2) == n ? 1 : i+2]) != first_turn)
            return false;
    }
    return true;
}
int is_inside(point p, vector<point> &v) {
    int n = v.size();

    bool on_polygon = false;
    for (int i=0; i<n-1; i++) {
        if (fabs(dist(p, v[i]) + dist(p, v[i+1]) - dist(v[i], v[i+1])) < EPS)
            on_polygon = true;
    }
    if (on_polygon) return 0;

    double sum = 0.0;
    for (int i=0; i<n-1; i++) {
        if (ccw(p, v[i], v[i+1])) sum += angle(v[i], p, v[i+1]);
        else                      sum -= angle(v[i], p, v[i+1]);

    }
    return fabs(sum) > M_PI ? 1 : -1;
}
vector<point> chull(vector<point> &v) {
    int n = v.size();
    int k = 0;
    vector<point> H(2*n);
    sort(v.begin(), v.end());

    for (int i=0; i<n; i++) {
        while ((k >= 2) && !ccw(H[k-2], H[k-1], v[i])) k--;
        H[k++] = v[i];
    }
    for (int i=n-2, t=k+1; i>=0; i--) {
        while ((k >= t) && !ccw(H[k-2], H[k-1], v[i])) k--;
        H[k++] = v[i];
    }
    H.resize(k);
    return H;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	point a = point(1,2);
	cout << a << endl;

    point b = {0,0};
    point c = {-2, 1};

    cout << angle(a,b,c) << endl;

	return 0;
}
