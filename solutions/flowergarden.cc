#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound) {
    sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i=2; i<sieve_size; i++) {
        if (!bs[i]) continue;

        for (ll j=i*i; j<sieve_size; j+=i) bs[j] = 0;
        p.push_back(i);
    }
}

bool prime(ll N) {
    if (N < sieve_size) return bs[N];
    for (int i=0; i<p.size() && p[i]*p[i]<=N; i++) {
        if (N%p[i] == 0) return false;
    }
    return true;
}

int T;
int N, D;

double l2(pair<double, double> a, pair<double, double> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    sieve(1e7);

	cin >> T;
	while (T--) {
		cin >> N >> D;

		vector<pair<double, double>> flowers(N);
		for (auto& [x, y]: flowers) cin >> x >> y;

		vector<double> dist(N+1);
        dist[1] = l2(flowers[0], {0, 0});
        for (int i=2; i<=N; i++) dist[i] = dist[i-1] + l2(flowers[i-1], flowers[i-2]);

        int ans = N;
        while (ans > 0 and !(prime(ans) and dist[ans] <= D)) ans--;

        cout << ans << endl;
	}

	return 0;
}
