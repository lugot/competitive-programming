#include <bits/stdc++.h>

using namespace std;

const double PI = 2.0*acos(0.0);
const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	double R,C;
	cin >> R >> C;

	double pizza = R*R;
	double cheese = (R-C)*(R-C);
	
	if (cheese<EPS) cout << "0\n";
	else
	printf("%.6lf", cheese/pizza*100);

	return 0;
}
