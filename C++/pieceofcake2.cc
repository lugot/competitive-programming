#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,h,v;
	cin >> n >> h >> v;

	printf("%d\n", max(max(max( h*v*4,
								(n-h)*v*4 ),
								h*(n-v)*4 ),
								(n-h)*(n-v)*4) );



	return 0;
}
