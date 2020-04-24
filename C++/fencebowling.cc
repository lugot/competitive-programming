#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k,w,l;
	cin >> k >> w >> l;

	int c=1;
	int sum=1;
	for(int i=0; i<k-1; i++){
		c*=2;
		sum+=2*c;
	}
	sum+=2*c;
	
	double alpha = 180.0/M_PI*atan((2.0*l)/(w*sum));

	printf("%.6lf\n", alpha);

	return 0;
}
