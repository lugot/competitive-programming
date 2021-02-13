#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
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
void rotate(point a, double theta, point &r){
	r = point(a.x*cos(theta) - a.y*sin(theta),
			a.x*sin(theta) - a.y*cos(theta));
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
double dist_to_line(point a, point p1, point p2, point &r){
	// p1 and p2 defines the line, a is our point
	point v = p2-p1;
	v.normalize();
	double u = dot(a-p1, v);
	
	r = p1 + v*u;
	return dist(a, r);
}
double dist_to_segment(point a, point p1, point p2, point &r){
	point v = p2-p1;
	v.normalize();
	double u = dot(a-p1, v);

    // no c
    //if (collinear(a, p1, p2)){
        //return min(dist(a, p1), dist(a, p2));
    //}

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


point dummy;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    
    while(t--){
        int n_inner, n_outer;
        vector<point> inner, outer;

        cin >> n_inner;
        double x, y;
        for(int i=0; i<n_inner; i++){
            cin >> x >> y;
            inner.push_back({x,y});
        }

        cin >> n_outer;
        for(int i=0; i<n_outer; i++){
            cin >> x >> y;
            outer.push_back({x,y});
        }
        //outer.push_back(outer[0]);

        double ans = 10000000.0;
        for(point pi: inner){
            for(int i=0; i<outer.size(); i++){
                ans = min(ans, dist_to_segment(pi, outer[i], outer[(i+1)%n_outer], dummy));
            }
        }
        //for(point pi: outer){
            //for(int i=0; i<inner.size(); i++){
                //ans = min(ans, dist_to_segment(pi, inner[i], inner[(i+1)%n_inner], dummy));
            //}
        //}
        cout << setprecision(14) << ans/2 << endl;
    }

	return 0;
}
