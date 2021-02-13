#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
	
	double x,y,r;
	while(cin >> x >> y >> r){
		double zx = 0.0, zy = 0.0;

		bool converge=true;
		while(r--){
			double zxt = zx, zyt = zy;

			zx = zxt*zxt - zyt*zyt + x;
			zy = 2*zxt*zyt + y;

			if (sqrt(zx*zx + zy*zy)>2){
				converge=false;
				break;
			}
		}
		if (converge) cout << "Case " << t++ << ": IN\n";
		else		  cout << "Case " << t++ << ": OUT\n";
	}


	return 0;
}
