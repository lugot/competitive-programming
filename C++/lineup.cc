#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, inc=0, dec=0;
	string a,b;
		
	cin >> T >> a >> b;
	T-=2;

	if (b.compare(a)>0) inc=1;
	else dec=1;

	while(T--) {
		a=b;
		cin >> b;
		if (inc && b.compare(a)<0) inc=0;
		else if (dec && b.compare(a)>0) dec=0;
		
	}
	if (inc) cout << "INCREASING\n";
	else if (dec) cout << "DECREASING\n";
	else cout << "NEITHER\n";

	return 0;
}
