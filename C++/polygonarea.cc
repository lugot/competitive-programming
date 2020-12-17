#include <bits/stdc++.h>
#include <vector>

using namespace std;

const double PI = 2.0*acos(0.0);
const double EPS = 1e-12;

double DEG2RAD(double d) { return d * PI / 180.0; }
double RAD2DEG(double r) { return r * 180.0 / PI; }

struct point{
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y): x(_x), y(_y){}

	double length() { return sqrt(x*x+y*y); }
	bool operator<(point n){
		if (fabs(x - n.x) > EPS) return x < n.x;
		return y < n.y;
	}
	int normalize(){
		double l = length();
		if(fabs(l) < EPS) return -1;
		x/=l; y/=l;
		return 0;
	}
	point operator+(point a){
		point r; r.x=x+a.x; r.y=y+a.y;
		return r;
	}
	point operator-(point a){
		point r; r.x=x-a.x; r.y=y-a.y;
		return r;
	}
	point operator*(double sc){
		point r; r.x=x*sc; r.y=y*sc;
		return r;
	}
};
double dist(point& a, point& b){
	return hypot(a.x - b.x, a.y - b.y);
}
double dot(point a, point b){
	return a.x*b.x + a.y*b.y;
}
double cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}
bool ccw(point a, point b, point c){
    return cross(b-a, c-a) > EPS;
}
bool collinear(point a, point b, point c){
    return fabs(cross(b-a, c-a)) < EPS;
}
void rotate(point a, point b, double theta, point &r){ // b around a CW
    b = b-a;
	r = point(b.x*cos(theta) - b.y*sin(theta),
              b.x*sin(theta) + b.y*cos(theta));
    r = r + a;
}
double angle(point a, point b, point c){ // angle aBc
    point ba = a-b;
    point bc = c-b;

    return acos(dot(ba, bc) / sqrt(dot(ba,ba)*dot(bc,bc)));
}
ostream& operator<<(ostream& os, point &p){ 
	os << "(" << p.x << "," << p.y << ")";
	return os;
}
void show(vector<point> &v){
	for(point &p: v) cout << p << endl;
	cout << endl;
}

struct line{
	double a, b, c;
	line() { a = b = c = 0.0; }
	line(point p1, point p2){
		if (fabs(p1.x-p2.x) < EPS){
			a = 1.0;
			b = 0.0;
			c = -p1.x;
		}
		else{
			a = -(p1.y-p2.y)/(p1.x-p2.x);
			b = 1.0;
			c = -a*p1.x - p1.y;
		}
	}
	line(point p1, double m){
		a = -m;
		b = 1.0;
		c = -(a*p1.x) + b*p1.y;
	}
};
bool are_parallel(line l1, line l2){
	return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}
bool are_same(line l1, line l2){
	return are_parallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}
bool are_intersect(line l1, line l2, point &p){
    if (are_parallel(l1, l1)) return false;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    // vertical line test
    if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
    else                  p.y = -(l2.a*p.x + l2.c);
    return true;
}
double dist_to_line(point a, point p1, point p2, point &r){
	// p1 and p2 defines the line, a is our point
	point v = p2-p1;
	v.normalize();
	double u = dot(a-p1, v);
	
	r = p1 + v*u;
	return dist(a, r);
}

struct seg{
    point a, b;
};
bool are_intersect(seg s1, seg s2){
    // NOT SPECIAL COLLINEAR CASE!
    if (ccw(s1.a, s1.b, s2.a) != ccw(s1.a, s1.b, s2.b) and
        ccw(s2.a, s2.b, s1.a) != ccw(s2.a, s2.b, s1.b))
        return true;

    return false;
}
double dist_to_segment(point a, point p1, point p2, point &r){
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

typedef vector<point> poly;
double perimeter(poly v){
    double ans = 0.0;
    int n = v.size();
    for (int i=0; i<n; i++)
        ans += dist(v[i], v[(i+1)%n]);

    return ans;
}
double area(poly v) {
    double ans = 0.0;
    int n = v.size();
    for (int i=0; i<n; i++)
        //ans += v[i].x*v[(i+1)%n].y - v[(i+1)%n].x*v[i].y;
        ans += cross(v[i], v[(i+1)%n]);

    return fabs(ans)/2.0;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<point> v;
        double x, y;
        while (n--) {
            cin >> x >> y;
            v.push_back({x, y});
        }
        n = v.size();

        bool ccw_test = true;
        for (int i=0; i<n; i++) {
            point a = v[i];
            point b = v[(i+1)%n];
            point c = v[(i+2)%n];
            if (collinear(a, b, c)) continue;

            if (!ccw(a, b, c)) ccw_test = false;
        }

        string ans = ccw_test ? "CCW" : "CW";

        cout << ans << " " << fixed << setprecision(1) << area(v) << endl;
    }

	return 0;
}
