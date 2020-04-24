#include <bits/stdc++.h>
#define MAX_SIZE 1000

using namespace std;

const double PI = 2.0*acos(0.0);
const double EPS = 1e-9; //too small/big???
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct PT {
	double x,y;
	double length() { return sqrt(x*x+y*y); }
	int normalize(){
		double l = length();
		if(fabs(l)<EPS) return -1;
		x/=l; y/=l;
		return 0;
	}
	PT operator-(PT a){
		PT r; r.x=x-a.x; r.y=y-a.y;
		return r;
	}
	PT operator+(PT a){
		PT r; r.x=x+a.x; r.y=y+a.y;
		return r;
	}
	PT operator*(double sc){
		PT r; r.x=x*sc; r.y=y*sc;
		return r;
	}
};
void rotate(PT p0, PT p1, double a, PT& r){
	// rotate p1 around $p_0$ counter-clockwise, by angle $a$
	// don’t pass by reference for p1, so r and p1 can be the same
	p1 = p1-p0;
	r.x = cos(a)*p1.x-sin(a)*p1.y;
	r.y = sin(a)*p1.x+cos(a)*p1.y;
	r = r+p0;
}
double dist(PT& a, PT& b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void show(PT& p){
	cout << "(" << p.x << ", " << p.y << ")" << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	while(T--){		
		string cmd;
		double val;
		
		int n;
		cin >> n;

		PT t = {0,0};
		PT O = {0,0};
		PT mov = {1,0};	
		int angle = 0;

		while(n--){
			cin >> cmd >> val;

			if (cmd == "fd"){
				PT mov = {1,0};	
				rotate(O, mov , DEG_to_RAD(angle) , mov);
				mov.normalize();
				
				mov = mov*val;
				t = t + mov;
			}
			if (cmd == "bk"){
				PT mov = {1,0};	
				rotate(O, mov, DEG_to_RAD(angle), mov);
				mov.normalize();
				
				mov = mov*val*-1;
				t = t + mov;
			}
			if (cmd == "lt"){
				angle += val;
			}
			if (cmd == "rt"){
				angle -= val;
			}
		}


		cout << round(dist(t,O)) << endl;
	}

	return 0;
}
