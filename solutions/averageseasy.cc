#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll T, Ncs, Ne;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> Ncs >> Ne;

		vector<ll> cs(Ncs), e(Ne);
		for (ll& css: cs) cin >> css;
		for (ll& es: e) cin >> es;

		double mcs = 0;
		for (ll css: cs) mcs += css;
		mcs /= Ncs;

		double me = 0;
		for (ll es: e) me += es;
		me /= Ne;

		int ans = 0;
		for (ll css: cs) if (css < mcs and css > me) ans++;

		cout << ans << endl;
	}

	return 0;
}
