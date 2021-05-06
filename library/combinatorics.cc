#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int p = 1e9 + 7;
ll mod(ll x) { return ((x%p)+p)%p; }

vll fibs;
ll fib(ll n) {
    if (n <= 1) return n;
    if (n == 2) return 1L;

    if (fibs.size() > n and fibs[n] != -1) return fibs[n];

    fibs = vll(n+1, -1);
    fibs[0] = 0;
    fibs[1] = 1;
    for (ll i=2; i<=n; i++) fibs[i] = fibs[i-1] + fibs[i-2];

    return fibs[n];
}

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
    if (n%2 == 0) fn = mfibs[n] = fk * (2*fk1 - fk);
    else          fn = mfibs[n] = fk*fk + fk1*fk1;

    return fn;
}

double fast_power(double base, ll exp) {
    double ans = 1;

    while (exp > 0) {
        if ((exp & 1) != 0) ans = ans * base;

        exp = exp >> 1;
        base = base*base;
    }

    return ans;
}
ll binet_fib(ll n) {
    if (n <= 1) return n;
    if (n == 2) return 1L;

    double phi_ton = fast_power((1 + sqrt(5)) /2, n);
    return (ll) round((phi_ton - (1/phi_ton)) / sqrt(5));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    for (ll i=1; i<10000; i++) {
        ll a = fib(i);
        ll b = fast_fib(i);
        cout << i << ": " << a << " " << b << endl;
    }

    return 0;
}


