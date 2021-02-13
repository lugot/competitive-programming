#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		int l, n;
		cin >> l >> n;

		int ans_lower = 0, mx=0, mi=2000000;
		int x;
		while(n--){
			cin >> x;
			ans_lower = max(ans_lower, min(x,l-x));
			mx = max(mx,x);
			mi = min(mi,x);
		}

		int ans_upper = mx-mi + max(mi, l-mx);

		cout << ans_lower << " " << ans_upper << endl;

	}

	return 0;
}
