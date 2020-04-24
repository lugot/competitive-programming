#include <bits/stdc++.h>

using namespace std;

int main() {
	int e,f,c, soda=0;
	cin >> e >> f >> c;
	
	e += f;
	while (e>=c) {
		soda += e/c;
		e = e%c + e/c;
	}
	
	cout << soda << endl;


	return 0;
}
