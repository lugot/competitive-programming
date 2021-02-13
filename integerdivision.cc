#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, d;
	cin >> n >> d;

	unordered_map<ll, ll> bins;
	ll x;
	while(n--){
		cin >> x;
		bins[x/d]++;
	}

	ll ans = 0;
	for(auto [div, b]: bins) ans += b*(b-1)/2;

	cout << ans << endl;

	return 0;
}
