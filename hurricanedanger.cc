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
ostream& operator<<(ostream& os, point &p){ 
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
void show(vector<point> &v){
    for(point &p: v) cout << p << endl;
    cout << endl;
}

double dist_to_line(point a, point p1, point p2, point &r){
    // p1 and p2 defines the line, a is our point
    point v = p2-p1;
    v.normalize();
    double u = dot(a-p1, v);
    
    r = p1 + v*u;
    return dist(a, r);
}

struct city{
    string name;
    point p;
};

point p1, p2;
point useless;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p1.x = x1;
        p1.y = y1;
        p2.x = x2;
        p2.y = y2;

        vector<city> cities;

        int m;
        cin >> m;
        while(m--){
            string s;
            cin >> s >> x1 >> x2;

            cities.push_back({s, point(x1, x2)});
        }

		stable_sort(cities.begin(), cities.end(), [](city c1, city c2){
				return dist_to_line(c1.p, p1, p2, useless)  - 
				dist_to_line(c2.p, p1, p2, useless) < -EPS; // !!!!!!!!!!!!!!!!!!!!!!
				});

		double refdist = dist_to_line(cities[0].p, p1, p2, useless);
        cout << cities[0].name << " ";

        int i=1;
        while(i < cities.size() && 
				fabs(dist_to_line(cities[i].p, p1, p2, useless) - refdist) < EPS){

            cout << cities[i++].name << " ";
        }
        cout << endl;
    }

    return 0;
}
