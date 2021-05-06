#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll sieve_size;
bitset<10000010> bs;
vll primes;

void sieve(ll upperbound) {
    sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i=2; i<sieve_size; i++) {
        if (!bs[i]) continue;

        for (ll j=i*i; j<sieve_size; j+=i) bs[j] = 0;
        primes.push_back(i);
    }
}

bool prime(ll N) {
    if (N < sieve_size) return bs[N];
    for (int i=0; i<primes.size() && primes[i]*primes[i]<=N; i++) {
        if (N%primes[i] == 0) return false;
    }
    return true;
}

int n, x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	sieve(32001);
	vector<vector<pair<ll, ll>>> reps(32001);

	for (int i=0; i<primes.size(); i++) {
        for (int j=i; j<primes.size(); j++) {
            ll p1 = primes[i], p2 = primes[j];
            if (p1+p2 >= 32001) continue;

            reps[p1+p2].push_back({p1, p2});
        }
	}

    cin >> n;
    while (n--) {
        cin >> x;

        cout << x << " has " << reps[x].size() << " representation(s)" << endl;
        for (auto [p1, p2]: reps[x]) cout << p1 << "+" << p2 << endl;
        cout << endl;
    }


	return 0;
}
