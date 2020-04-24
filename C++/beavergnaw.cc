#include <bits/stdc++.h>

using namespace std;

int main() {
	double D,V;

	while(1) {
		cin >> D >> V;
		if (D==0) break;
		
		double a = D*D*D/4*M_PI;
		a -= V;
		a -= D*D*D/3/4*M_PI;
		a *= 1.5;

		double r = cbrt(a / (2*M_PI))*2;


		printf("%.6f\n",r);
	}


	return 0;
}
