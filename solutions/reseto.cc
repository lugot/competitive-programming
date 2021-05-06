#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll N, K;
ll crossed = 0;
ll sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound) {
    sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i=2; i<sieve_size; i++) {
        if (!bs[i]) continue;

        for (ll j=i; j<sieve_size; j+=i) {
			if (bs[j] == 0) continue;
			bs[j] = 0;

			crossed++;
			if (crossed == K) {
				cout << j << endl;
				return;
			}
		}
        //p.push_back(i);
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	sieve(N);

	return 0;
}
