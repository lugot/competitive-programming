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

vll prime_factors(ll N) {
	vll factors;

	for (int i=0; i<p.size() && p[i]*p[i]<=N; i++) {
		while (N%p[i] == 0) {
		  N /= p[i];
		  factors.push_back(p[i]);
		}
	}
	if (N != 1) factors.push_back(N);
	return factors;
}

ll x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	sieve(1e7);

	while (cin >> x) {
		if (x < 0) {
			cout << -1 << " ";
			x = -x;
		}

		vll factors = prime_factors(x);

		int mult = 0, prev = factors[0];
		for (ll factor: factors) {
			if (factor == prev) mult++;
			else {
				if (mult == 1) cout << prev << " ";
				else cout << prev << "^" << mult << " ";
				mult = 1;
			}
			prev = factor;
		}
		if (mult == 1) cout << prev << " ";
		else cout << prev << "^" << mult << " ";
		mult = 1;
		cout << endl;
	}

	return 0;
}
