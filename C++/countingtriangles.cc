#include <bits/stdc++.h>

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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    while(true){
        cin >> n;
        if (n==0) break;

        vector<seg> segs(n);
        double x1, y1, x2, y2;
        for(auto& x: segs){
            cin >> x1 >> y1 >> x2 >> y2;
            x = {point(x1, y1), point(x2, y2)};
        }

        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (i==j) continue;

                if (are_intersect(segs[i], segs[j])) adj[i].push_back(j);
            }
        }

        int ans = 0;
    
        vector<tuple<int, int, int>> tris;
        //for(vector<int> list1: adj){
        for(int i=0; i<adj.size(); i++){
            vector<int> list1 = adj[i];
            for(int e1: list1){ // 1 2 4
                for(int e2: adj[e1]){ // 0 2 3
                    if (find(list1.begin(), list1.end(), e2) != list1.end()){
                        vector<int> temp = {i, e1, e2};
                        sort(temp.begin(), temp.end());
            
                        tris.push_back({temp[0], temp[1], temp[2]});
                    }
                }
            }
        }

        sort(tris.begin(), tris.end());
        tris.erase(unique(tris.begin(), tris.end()), tris.end());

        cout << tris.size() << endl;
        //for(auto t: tris){
            //cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
        //}

        //for(int i=0; i<n; i++){
            //for(int j=0; j<adj[i].size(); j++){
                //for(int k=0; k<adj[j].size(); k++){
                    //if (find(adj[i].begin(), adj[i].end(), adj[j][k]) != adj[i].end()){
                        //ans++;
                        //cout << adj[i][j] << adj[j][k] << k << endl;
                    //}
                //}
            //}
        //}

        //cout << ans << endl;

        //for(int i=0; i<adj.size(); i++){
            //cout << i << ": ";
            //auto x = adj[i];
            //for(auto y: x) cout << y << " ";
            //cout << endl;
        //}



    }

	return 0;
}
