#include <bits/stdc++.h>

using namespace std;

const double PI = 2.0*acos(0.0);
const double EPS = 1e-9;

double DEG2RAD(double d) { return d * PI / 180.0; }
double RAD2DEG(double r) { return r * 180.0 / PI; }

struct point{
	double x,y;
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
			a.x*sin(theta) + a.y*cos(theta));
}
ostream& operator<<(ostream& os, point &p){ 
	os << "(" << p.x << "," << p.y << ")";
	return os;
}
void show(vector<point> &v){
	for(point &p: v) cout << p << endl;
	cout << endl;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		point pos(0,0);
		point dir(1,0);

		string cmd, val;
		//int x;
		vector<point> vectors;
		string missing;
		int breakpt;
		while(n--){
			cin >> cmd >> val;
			if (val[0] == '?'){
				missing  = cmd;
				if (cmd == "lt" or cmd == "rt"){
					breakpt = vectors.size();
				}
				continue;
			}
			int x = stoi(val);

			if (cmd == "bk"){
				x = -x;
				cmd = "fd";
			}
			if (cmd == "rt"){
				x = 360 - x;
				cmd = "lt";
			}

			if (cmd == "lt") rotate(dir, DEG2RAD(x), dir);
			if (cmd == "fd") vectors.push_back(dir*x); //pos = pos + dir*x;

			//cout << pos << " " << dir << endl;
		}
		for(point v: vectors) cout << v << " ";
		cout << endl;

		if (missing == "fd" or missing == "bk"){
			point missing_v = point();
			for(point v: vectors) missing_v = missing_v + v;

			cout << (int) round(missing_v.length()) << endl;
			//if (missing == "fd") cout << (int) round(missing_v.length()) << endl;
			//if (missing == "bk") cout << (int) round(missing_v.length()) << endl;

			cout << missing_v << endl;
		}
		else{

		}

	}

	return 0;
}
