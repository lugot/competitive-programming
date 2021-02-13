#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    vector<ll> items(n);
    for (auto &x: items) cin >> x;

    sort(items.rbegin(), items.rend());

    
    int i = 0;
    ll ans = 0;
    while (i < items.size()) {
        if (i % 3 == 2) ans += items[i];
        i++;
    }
    cout << ans << endl;


	return 0;
}
