#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,m;
	string a,b;
	cin >> n >> m >> a >> b;

	string p(m,' ');
	for (int i=m-n; i<m; i++) p[i]=a[i-m+n];
	
	for (int i=m-1; i>=n; i--) {
		int ki = b[i]-p[i];
		if (ki < 0) ki+=26;
		
		p[i-n] = ki + 'a';
	}
	cout << p << endl;


	return 0;
}
