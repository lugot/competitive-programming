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
	bool operator==(point a) {
		if (abs(a.x - x) < EPS and abs(a.y - y) < EPS) return true;
		return false;
	}
};
double cross(point a, point b) {
    return a.x*b.y - a.y*b.x;
}
bool ccw(point a, point b, point c) {
    return cross(b-a, c-a) > EPS;
}
ostream& operator<<(ostream& os, point &p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
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
struct segment {
    point a, b;
};
bool are_intersect(segment s1, segment s2) {
    // no check for collinear case
    if (ccw(s1.a, s1.b, s2.a) != ccw(s1.a, s1.b, s2.b) and
        ccw(s2.a, s2.b, s1.a) != ccw(s2.a, s2.b, s1.b))
        return true;

    return false;
}
void lines_intersection(line l1, line l2, point& r) {
	double det = l1.a*l2.b - l2.a*l1.b;
	r.x = -(l2.b*l1.c - l1.b*l2.c)/det;
	r.y = -(l1.a*l2.c - l2.a*l1.c)/det;
}

int n;
vector<vector<int>> alist;
vector<int> color;

bool bfs(int x) {
	//color = vector<int>(n, -1);
	//for (int& x: color) x = -1;

    queue<int> q;
    q.push(x);

	bool flag = true;
    while (!q.empty() and flag) {
        int u = q.front(); q.pop();

        for (auto v: alist[u]) {
            if (color[v] == -1) {
				color[v] = 1 - color[u];
				q.push(v);
			}
			else if (color[v] == color[u]) {
				flag = false;
				break;
			}
        }
    }

	return flag;
}


int main() {
	int w, p;
	cin >> w >> p;

	vector<point> wells(w);
	for (point& p: wells) cin >> p.x >> p.y;

	vector<segment> segs(p);
	for (segment& s: segs) {
		int i;
		cin >> i;

		s.a = wells[i-1];
		cin >> s.b.x >> s.b.y;
	}

	alist = vector<vector<int>>(p);
	n = p;

	for (int i=0; i<p; i++) {
		for (int j=i+1; j<p; j++) {
			if (!are_intersect(segs[i], segs[j]) and
					!(segs[i].b == segs[j].b)) continue;

			//point intersect;
			//lines_intersection(line(segs[i].a, segs[i].b),
							   //line(segs[j].a, segs[j].b),
							   //intersect);

			alist[i].push_back(j);
			alist[j].push_back(i);
		}
	}

	color = vector<int>(n, -1);
	bool ans = true;
	for (int x=0; x<p; x++) {
		ans &= bfs(x);
		if (ans == false) break;
	}
	if (ans) cout << "possible" << endl;
	else 	 cout << "impossible" << endl;


	return 0;
}
