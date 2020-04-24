#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-9;

struct PT{
	double x,y;

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
};
bool operator<(const PT& a,const PT& b){
	if(fabs(a.x-b.x)<EPS) return a.y<b.y;
	return a.x<b.x;
}

double trap(PT a, PT b){
	return (0.5*(b.x-a.x)*(b.y*a.y));
}

double triarea(PT a, PT b, PT c){
	return fabs(trap(a,b)+trap(b,c)+trap(c,a));
}

int pAndSeg(PT &p1, PT &p2, PT &p){
	double s = triarea(p,p1,p2);
	if (s>EPS) return 0;
	double sg = (p.x-p1.x)*(p.x-p2.x);
	if (sg>EPS) return -1;
	sg = (p.y-p1.y)*(p.y-p2.y);
	if (sg>EPS) return -1;
	return 1;
}

void rotate(PT p0, PT p1, double a, PT& r){
	p1 = p1-p0;
	r.x = cos(a)*p1.x-sin(a)*p1.y;
	r.y = sin(a)*p1.x+cos(a)*p1.y;
	r = r+p0;
}


int pAndPoly(vector<PT> pv, PT p){
	int i,j;
	int n = pv.size();
	pv.push_back(pv[0]);
	for(int i=0; i<n; i++)
		if (pAndSeg(pv[i],pv[i+1],p)==1) return -1;
	for(int i=0; i<n; i++) pv[i]=pv[i]-p;

	p.x=p.y=0.0;
	double a,y;
	
	while(1){
		a = (double)rand()/10000.0;
		j=0;
		for(int i=0; i<n; i++){
			rotate(p,pv[i], a, pv[i]);
			if (fabs(pv[i].x)<EPS) j=1;
		}

		if (j==0){
			pv[n]=pv[0];
			j=0;
			for(i=0; i<n; i++) if (pv[i].x*pv[i+1].x < EPS){
				y = pv[i+1].y - pv[i+1].x*(pv[i].y - pv[i+1].y)/
					(pv[i].x - pv[i+1].x);
				if (y>0) j++;
			}
			return j%2;
		}
	}

	return 1;

}

double area(vector<PT> &vin){
	int n=vin.size();
	double ret = 0.0;
	for(int i=0; i<n;i++)
		ret += trap(vin[i],vin[(i+1)%n]);
	return fabs(ret);
}

void show(PT& p){
	cout << "(" << p.x << "," << p.y << ")" << endl;
}
void show(vector<PT> &p){
	int i,n=p.size();
	for(i=0; i<n; i++) show(p[i]);
	cout << ":)" << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while(true){
		cin >> n;
		if (n==0) break;
	
		vector<PT> poly;
		double x,y;
		while(n--){
			cin >> x >> y;
			if (poly.size()==0 or true) poly.push_back({x,y});
			else{
				PT p;
				p.x=x; p.y=y;
				cout << "analizing point";
				if (pAndPoly(poly, p) ==0)
					poly.push_back({x,y});
				show(poly);
			}
		}
		//show(poly);
		sort(poly.begin(), poly.end());
		show(poly);
		cout << area(poly) << endl;
	}

	return 0;
}
