#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, t;
	while(cin >> n >> t){
		if (n  == 0) break;

		long long x, y;
		char c;
		cin >> x >> c >> y;

		if (c == '+'){
			long long ans = (x%n + y%n)%n;
			cout << ans << endl;
		}


	}

	return 0;
}
