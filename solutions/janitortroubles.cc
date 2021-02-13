#include <bits/stdc++.h>

using namespace std;

int main() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	double p = (a+b+c+d)/2.0;
	printf("%.6lf\n", sqrt( (p-a)*(p-b)*(p-c)*(p-d) ));

	return 0;
}
