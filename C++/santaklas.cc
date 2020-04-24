#include <bits/stdc++.h>
#define PI 2.0*acos(0.0)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	double H,v;
	cin >> H >> v;
	
	if (v<=180) cout << "safe\n";
	else{
		if (v<270) v = 90 - (v - 180);
		else v = 90 - (360 - v);
		cout << (int)(H/cos(v*PI/180.0)) << endl;
	}

	return 0;
}
