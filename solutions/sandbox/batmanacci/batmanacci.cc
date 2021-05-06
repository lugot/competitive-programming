#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ull> vll;

vll fibs;
void fib() {
    fibs = vll(100010, -1);

    fibs[0] = 0;
    fibs[1] = 1;
    int i=2;
    while (fibs[i-1] <= 1e18) {
        fibs[i++] = fibs[i-1] + fibs[i-2];
    }
}

char batman(ull N, ull K) {
    N = N > 89 ? 89 : N;

    while (N > 2) {
        if (K <= fibs[N-2]) N -= 2;
        else {
            K -= fibs[N-2];
            N--;
        }
    }
    if (N == 1) return 'N';
    return 'A';
}

ull N, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> K;

    fib();
    cout << batman(N, K) << endl;

	return 0;
}
