#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	double x1,y1,x2,y2,p;
	while(1){
		cin >> x1;
		if (x1==0) break;
		cin >> y1 >> x2 >> y2 >> p;

		printf("%.4f\n", pow( pow( abs(x1-x2), p) + pow( abs(y1-y2), p), (1/p)) );

	}


	return 0;
}
