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

//in main  sieve(1e7);


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

// third part

int numPF(ll N) {
  int ans = 0;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ++ans; }
  return ans + (N != 1);
}

int numDiffPF(ll N) {
  int ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
    if (N%p[i] == 0) ++ans;                      // count this prime factor
    while (N%p[i] == 0) N /= p[i];               // only once
  }
  if (N != 1) ++ans;
  return ans;
}

ll sumPF(ll N) {
  ll ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ans += p[i]; }
  if (N != 1) ans += N;
  return ans;
}

int numDiv(ll N) {
  int ans = 1;                                   // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    int power = 0;                               // count the power
    while (N%p[i] == 0) { N /= p[i]; ++power; }
    ans *= power+1;                              // follow the formula
  }
  return (N != 1) ? 2*ans : ans;                 // last factor = N^1
}

ll sumDiv(ll N) {
  ll ans = 1;                                    // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    ll multiplier = p[i], total = 1;
    while (N%p[i] == 0) {
      N /= p[i];
      total += multiplier;
      multiplier *= p[i];
    }                                            // total for
    ans *= total;                                // this prime factor
  }
  if (N != 1) ans *= (N+1);                      // N^2-1/N-1 = N+1
  return ans;
}

ll EulerPhi(ll N) {
  ll ans = N;                                    // start from ans = N
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    if (N%p[i] == 0) ans -= ans/p[i];            // count unique
    while (N%p[i] == 0) N /= p[i];               // prime factor
  }
  if (N != 1) ans -= ans/N;                      // last factor
  return ans;
}
