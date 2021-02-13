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
			a.x*sin(theta) - a.y*cos(theta));
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

	int n;
	double t;
	cin >> n >> t;

	vector<point> act;
	vector<int> ti;
	int x, y, z;
	for(int i=0; i<n; i++){
		cin >> x >> y >> z;
		act.push_back(point(x,y));
		ti.push_back(z);
	}


	vector<point> vec;
	for(int i=1; i<n; i++){
		vec.push_back(act[i] - act[i-1]);
	}


	vector<point> gps;
	gps.push_back(act[0]);

	double act_time = t,
		end_time = ti[ti.size()-1];
	while(act_time < end_time){
		int i=0;
		while(i < n-1 and act_time > ti[i+1]) i++;

		if (act_time == ti[i]){
			gps.push_back(act[i]);
			act_time += t;
			continue;
		}

		double timediff = (act_time - ti[i])/(ti[i+1] - ti[i]);
		point endpt = act[i] + vec[i]*timediff;
		act_time += t;

		//cout << i << " " << timediff << endl;

		gps.push_back(endpt);
	}
	gps.push_back(act[act.size()-1]);

	double act_path_lenght = 0.0;
	for(int i=1; i<act.size(); i++) act_path_lenght += dist(act[i], act[i-1]);

	double gps_path_length = 0.0;
	for(int i=1; i<gps.size(); i++) gps_path_length += dist(gps[i], gps[i-1]);


	//cout << act_path_lenght << " " << gps_path_length << endl;
	//show(gps);
	
	cout << fixed << setprecision(6) 
		<< 100*(1- gps_path_length/act_path_lenght) << endl;


	return 0;
}
