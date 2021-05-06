#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int p = 1e9 + 7;
ll mod(ll x) { return ((x%p)+p)%p; }

map<ll, ll> mfibs;
ll fast_fib(ll n) {
    if (n <= 1) return n;
    if (n == 2) return 1L;

    ll k;
    if (n%2 == 0) k = n/2;
    else          k = (n-1) / 2;

    ll fk;
    if (mfibs.count(k)) fk = mfibs[k];
    else                fk = mfibs[k] = fast_fib(k);

    ll fk1;
    if (mfibs.count(k+1)) fk1 = mfibs[k+1];
    else                  fk1 = mfibs[k+1] = fast_fib(k+1);

    ll fn;
    if (n%2 == 0) fn = mfibs[n] = mod(fk * mod(mod(2*fk1) - mod(fk)));
    else          fn = mfibs[n] = mod(mod(fk*fk) + mod(fk1*fk1));

    return mod(fn);
}

ll T, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (cin >> n) cout << fast_fib(n+2) << endl;

	return 0;
}
