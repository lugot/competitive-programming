#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int l, d, n;
    cin >> l >> d >> n;

    vector<int> birds(n);
    for (auto &x: birds) cin >> x;
    //birds.push_back(6);
    //birds.push_back(l-6);

    sort(birds.begin(), birds.end());

    int curr = 6;
    int ans = 0;
    for (int b: birds) {
        while (b - curr >= d) {
            ans++;
            curr += d;
        }
        curr = b + d;
    }
    while (curr <= l-6) {
        ans++;
        curr += d;
    }

    if (n == 0) ans = (l-6*2)/d + 1;

    cout << ans << endl;

	return 0;
}
