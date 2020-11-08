#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.0 + 1e-6;

double f(double n, double p, double s, double v, double c){
	double u = n+0.0;
	double ans = n/(p*1e9)*pow(log2(n), c*sqrt(2)) + s/v*(1+1/c);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double p, s, v;
	cin >> n >> p >> s >> v;

	double right, left;
	right = 100.0;
	left = 1.0;

	while(abs(right - left) > EPS) {
		double left_third = left + (right - left) / 3,
			 right_third = right - (right - left) / 3;

		if (f(n, p, s, v, left_third) > f(n, p, s, v, right_third))
		  left = left_third;
		else
		  right = right_third;
	}

	double c = (left+right)/2;
	cout << fixed << setprecision(8);
	cout << f(n, p, s, v, c) << " " << c << endl; 

	return 0;
}
