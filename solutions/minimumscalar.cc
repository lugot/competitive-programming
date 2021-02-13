#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int test_case=1; test_case<=T; test_case++){
		int n;
		cin >> n;
		vector<ll> v1(n), v2(n);

		for(auto &x: v1) cin >> x;
		for(auto &x: v2) cin >> x;

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end(), greater<ll>());

		ll ans = 0;
		for(int i=0; i<n; i++) ans += v1[i]*v2[i];

		cout << "Case #" << test_case << ": " << ans << endl;
	}


	return 0;
}
