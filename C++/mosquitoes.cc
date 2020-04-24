#include <bits/stdc++.h>
#define MAX_SIZE 1000

using namespace std;

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
	
	PT operator*(long double sc){
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
double dot(PT& a, PT& b){
	// the inner product of two vectors
	return(a.x*b.x+a.y*b.y);
}

double trap(PT a, PT b){
	return (0.5*(b.x - a.x)*(b.y + a.y));
}

double area(vector<PT> &vin){
// Area of a simple polygon, not neccessary convex
	int n = vin.size();
	double ret = 0.0;
	for(int i = 0; i < n; i++)
	ret += trap(vin[i], vin[(i+1)%n]);
	return fabs(ret);
}

double peri(vector<PT> &vin){
	// Perimeter of a simple polygon, not neccessary convex
	int n = vin.size();
	double ret = 0.0;
	for(int i = 0; i < n; i++)
		ret += dist(vin[i], vin[(i+1)%n]);
	return ret;
}

double triarea(PT a, PT b, PT c){
	return fabs(trap(a,b)+trap(b,c)+trap(c,a));
}

double height(PT a, PT b, PT c){
	// height from a to the line bc
	double s3 = dist(c, b);
	double ar=triarea(a,b,c);
	return(2.0*ar/s3);
}

// ========
//  Angles
// ========
double angle(PT& p1, PT& p2, PT& p3){
	// angle from p1->p2 to p1->p3, returns -PI to PI
	PT va = p2-p1;
	va.normalize();
	PT vb; vb.x=-va.y; vb.y=va.x;
	PT v = p3-p1;
	double x,y;
	x=dot(v, va);
	y=dot(v, vb);
	return(atan2(y,x));
}

double angle(double a, double b, double c){
	// in a triangle with sides a,b,c, the angle between b and c
	// we do not check if a,b,c is a triangle here
	double cs=(b*b+c*c-a*a)/(2.0*b*c);
	return(acos(cs));
}

void rotate(PT p0, PT p1, double a, PT& r){
	// rotate p1 around p0 clockwise, by angle a
	// don’t pass by reference for p1, so r and p1 can be the same
	p1 = p1-p0;
	r.x = cos(a)*p1.x-sin(a)*p1.y;
	r.y = sin(a)*p1.x+cos(a)*p1.y;
	r = r+p0;
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
	
	int n,m;
	double d,x,y;

	cin >> n;
	while(n--){
		cin >> m >> d;
		//d+=1e-5;
		
		vector<PT> mos;
		while(m--){
			cin >> x >> y;
			mos.push_back({x,y});
		}

		int max_mos = 0;
		for(int i=0; i<mos.size(); i++) for(int j=i+1; j<mos.size(); j++){
			vector<PT> points_to_analize;

			if (dist(mos[i], mos[j]) > d) continue;
			else{
				PT p1,p2, rot;
				double ang = angle(d/2.0, d/2.0, dist(mos[i], mos[j]));
				cout << ang << endl;	
				rot = mos[j] - mos[i];
				rot.normalize();
				rot = p1*(d/2);
				rotate(mos[i], rot,  ang, p1); 
				rotate(mos[i], rot, -ang, p2); 
			
				points_to_analize.push_back(p1);
				points_to_analize.push_back(p2);
			}


			int sum = 0;
			for(int j=0; j<points_to_analize.size(); j++){
				
				sum=0;
				for(int m=0; m<mos.size(); m++){
					PT mosq = mos[m] - points_to_analize[j];
					if (mosq.length() -d/2.0 < EPS) sum++;
				}
				max_mos = max(max_mos, sum);

			}
			
		}


		cout << max_mos << endl;
	}


	

	return 0;
}
