#include <bits/stdc++.h>
#include <math.h>

using namespace std;

const double PI = 2.0*acos(0.0);
const double EPS = 1e-9;

double DEG2RAD(double d) { return d * PI / 180.0; }
double RAD2DEG(double r) { return r * 180.0 / PI; }

struct point{
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y): x(_x), y(_y){}

	double length() { return sqrt(x*x+y*y); }
	bool operator<(const point& n) const {
		if (fabs(x - n.x) > EPS) return x < n.x;
		return y < n.y;
    }
    bool operator==(const point a) {
        if (fabs(x-a.x) < EPS and fabs(y-a.y) < EPS) return true;
        return false;
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
double dist(point a, point b){
	return hypot(a.x - b.x, a.y - b.y);
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

point center;
void sort_ccw(vector<point>&v ) {
    int n = v.size();
    for (point p: v) center = center + p;
    center = center*(1.0/n);

    sort(v.begin(), v.end(), [](point a, point b){
            return atan2(a.y-center.y, a.x-center.x) < atan2(b.y-center.y, b.x-center.x);
            });
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<point> v(n);
        for (point &p: v) cin >> p.x >> p.y;

        vector<point> hull = chull(v);
        hull.pop_back();

        //set<point> s(hull.begin(), hull.end());
        //hull.assign(s.begin(), s.end());
        //sort_ccw(hull);
        
        vector<point> newhull;
        newhull.push_back(hull[0]);

        for (int i=1; i<hull.size(); i++) {
            if (hull[i] == newhull[newhull.size()-1]) continue;
            newhull.push_back(hull[i]);
        }
        hull = newhull;

        sort_ccw(hull);
        
        cout << hull.size() << endl;
        for (point p: hull) cout << p.x << " " << p.y << endl;
    }

	return 0;
}
