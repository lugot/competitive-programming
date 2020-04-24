#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000

const double PI = 2.0*acos(0.0);
const double EPS = 1e-9; //too small/big?????

struct PT {
	double x,y;
	
	double length() { return sqrt(x*x+y*y); }
	int normalize(){
		// normalize the vector to unit length; return -1 if the vector is 0
		double l = length();
		if(fabs(l)<EPS) return -1;
		x/=l; y/=l;
		return 0;
	}

	PT operator-(PT a){
		PT r;
		r.x=x-a.x; r.y=y-a.y;
		return r;
	}
	
	PT operator+(PT a){
		PT r;
		r.x=x+a.x; r.y=y+a.y;
		return r;
	}
	
	PT operator*(double sc){
		PT r;
		r.x=x*sc; r.y=y*sc;
		return r;
	}
};

bool operator<(const PT& a,const PT& b){
	if(fabs(a.x-b.x)<EPS) return a.y<b.y;
	return a.x<b.x;
}

double dist(PT& a, PT& b){
// the distance between two points
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int sideSign(PT& p1, PT& p2, PT& p3){
	// which side is p3 to the line p1->p2? returns: 1 left, 0 on, -1 right
	double sg = (p1.x-p3.x)*(p2.y-p3.y)-(p1.y - p3.y)*(p2.x-p3.x);
	if(fabs(sg)<EPS) return 0;
	if(sg>0) return 1;
	return -1;
}

bool better(PT& p1,PT& p2,PT& p3){
	// used by convec hull: from p3, if p1 is better than p2
	double sg = (p1.y - p3.y)*(p2.x-p3.x)-(p1.x-p3.x)*(p2.y-p3.y);
	//watch range of the numbers
	if(fabs(sg)<EPS){
		if(dist(p3,p1) > dist(p3,p2))return true;
		else return false;
	}
	if(sg<0) return true;
	return false;
}

//convex hull nlogn
void vex2(vector<PT> vin, vector<PT>& vout){
	// vin is not pass by reference, since we will rotate it
	vout.clear();
	int n=vin.size();
	sort(vin.begin(),vin.end());
	PT stk[MAX_SIZE];
	int pstk, i;
	// hopefully more than 2 points
	stk[0] = vin[0];
	stk[1] = vin[1];
	pstk = 2;
	for(i=2; i<n; i++){
		if(dist(vin[i], vin[i-1])<EPS) continue;
		while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]))
		pstk--;
		stk[pstk] = vin[i];
		pstk++;
	}
	
	for(i=0; i<pstk; i++) vout.push_back(stk[i]);
	
	// turn 180 degree
	for(i=0; i<n; i++){
		vin[i].y = -vin[i].y;
		vin[i].x = -vin[i].x;
	}
	
	sort(vin.begin(), vin.end());
	
	stk[0] = vin[0];
	stk[1] = vin[1];
	pstk = 2;
	
	for(i=2; i<n; i++){
		if(dist(vin[i], vin[i-1])<EPS) continue;
		while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2])) pstk--;
		
		stk[pstk] = vin[i];
		pstk++;
	}
	
	for(i=1; i<pstk-1; i++){
		stk[i].x= -stk[i].x; // don’t forget rotate 180 d back.
		stk[i].y= -stk[i].y;
		vout.push_back(stk[i]);
	}
}

void show(PT& p){
	cout << "(" << p.x << ", " << p.y << ")" << endl;
}
void show(vector<PT>& p){
	int i,n=p.size();
	for(i=0;i<n;i++) show(p[i]);
	cout << ":)" << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int C;
	cin >> C;

	double x,y;
	vector<PT> points;
	while(C--){
		cin >> x >> y;
		points.push_back({x,y});
	}

	vector<PT> CH;
	vex2(points, CH);
	
	//show(CH);
	double maxdst=0.0;
	for(int i=0; i<CH.size(); i++){
		for(int j=i+1; j<CH.size(); j++){
			maxdst=max(maxdst,dist(CH[i],CH[j]));
		}
	}

	printf("%0.9lf\n", maxdst);
	return 0;
}
