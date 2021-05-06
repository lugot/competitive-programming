#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll n;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    sieve(1e7);

	while (cin >> n) {
        if (n == 0) return 0;

        ll x = 2*n;

        while (!prime(x)) x++;
        if (!prime(n)) cout << x << " (" << n << " is not prime)" << endl;
        else           cout << x << endl;
	}

	return 0;
}
