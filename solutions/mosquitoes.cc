#include <bits/stdc++.h>
#include <vector>

using namespace std;

const double EPS = 1e-9;

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
double distsq(point& a, point& b) {
    return pow(a.x-b.x, 2) + pow(a.y - b.y, 2);
}
ostream& operator<<(ostream& os, point &p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int m;
        double d;
        cin >> m >> d;
        
        d = d/2;

        vector<point> mosquitoes(m);
        for (point& m: mosquitoes) cin >> m.x >> m.y;

        vector<point> middle;
        for (point m: mosquitoes) for (point v: mosquitoes) {
            point c;
            if (circle_ptsrad(m, v, d, c)) middle.push_back(c);
            if (circle_ptsrad(v, m, d, c)) middle.push_back(c);
            middle.push_back((m+v)*0.5);
        }

        int ans = 0;
        for (point m: middle) {
            int act_ans = 0;
            //for (point v: mosquitoes) if (distsq(m, v) - d*d < EPS) act_ans++;
            for (point v: mosquitoes) if (dist(m, v) - d-1e-5 <= EPS) act_ans++;

            //cout << m << " " << act_ans << endl;
            ans = max(ans, act_ans);
        }

        cout << ans << endl;
    }

	return 0;
}
