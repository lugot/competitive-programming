#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;	
	
	while(T--) {
		int n,m;
		cin >> n >> m;

		int a,b;
		for (int i=0; i<m; i++) {
			cin >> a >> b;
		}
		printf("%d\n", m<n ? m : n-1 );
	}

	return 0;
}
