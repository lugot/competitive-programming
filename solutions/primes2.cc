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

int T;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	sieve(1e7);

	cin >> T;
	while (cin >> s) {

		bool is_bin, is_oct, is_dec, is_hex;
		is_bin = is_oct = is_dec = is_hex = true;
		for (char c: s) {
			if (c >= '2') {
				is_bin = false;
			}
			if (c >= '8') {
				is_bin = false;
				is_oct = false;
			}
			if (c >= 'A') {
				is_bin = false;
				is_oct = false;
				is_dec = false;
			}
		}

		set<ll> possibilites;
		ll ans, idx;

		ans = idx = 0;
		for (int i=s.length()-1; i>=0; i--) {
			if (s[i] >= 'A') ans += (ll) (s[i]-'A'+10) * pow(16, idx++);
			else             ans += (ll) (s[i]-'0') * pow(16, idx++);
		}
		possibilites.insert(ans);

		if (is_dec) {
			ans = idx = 0;
			for (int i=s.length()-1; i>=0; i--) {
				ans += (ll) (s[i]-'0') * pow(10, idx++);
			}
			possibilites.insert(ans);
		}

		if (is_oct) {
			ans = idx = 0;
			for (int i=s.length()-1; i>=0; i--) {
				ans += (ll) (s[i]-'0') * pow(8, idx++);
			}
			possibilites.insert(ans);
		}

		if (is_bin) {
			ans = idx = 0;
			for (int i=s.length()-1; i>=0; i--) {
				ans += (ll) (s[i]-'0') * pow(2, idx++);
			}
			possibilites.insert(ans);
		}

		ans = 0;
		for (ll n: possibilites) if (prime(n)) ans++;

		ll num = ans;
		ll den = possibilites.size();

		if (num == 0) den = 1;

		int gcd = __gcd(num, den);
		num /= gcd;
		den /= gcd;

		cout << num << "/" << den << endl;

	}

	return 0;
}
