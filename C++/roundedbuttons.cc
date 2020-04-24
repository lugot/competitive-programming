#include <bits/stdc++.h>

#define PI 2.0*acos(0.0)

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	double x,y,w,h,r;
	int m;
	double xm, ym;
	while(n--){
		cin >> x >> y >> w >> h >> r;
		cin >> m;
		
		while(m--){
			cin >> xm >> ym;

			bool inside = false;
			if (xm >= x+r && xm <= x+w-r && 
				ym >= y && ym <= y+h) inside = true;
			
			if (xm >= x && xm <= x+w && 
				ym >= y+r && ym <= y+h-r){
				inside = true;
			}
			xm = xm - x - r;
			ym = ym - y - r;
			if (sqrt(xm*xm + ym*ym) < r) inside = true;
			xm = xm + x + r;
			ym = ym + y + r;

			xm = xm - x + r - w;
			ym = ym - y - r;
			if (sqrt(xm*xm + ym*ym) < r) inside = true;
			xm = xm + x - r + w;
			ym = ym + y + r;

			xm = xm - x - r;
			ym = ym - y + r - h;
			if (sqrt(xm*xm + ym*ym) < r) inside = true;
			xm = xm + x + r;
			ym = ym + y - r + h;
		
			xm = xm - x + r - w;
			ym = ym - y + r - h;
			if (sqrt(xm*xm + ym*ym) < r) inside = true;
			xm = xm + x - r + w;
			ym = ym + y - r + h;
		
			if (inside) cout << "inside\n";
			else cout << "outside\n";
		}
		cout << endl;
	}

	return 0;
}
