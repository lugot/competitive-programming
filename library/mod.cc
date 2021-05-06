int mod(int a, int m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

int modPow(int b, int p, int m) {                // assume 0 <= b < m
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);                   // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

int extEuclid(int a, int b, int &x, int &y) {    // pass x and y by ref
  int xx = y = 0;
  int yy = x = 1;
  while (b) {                                    // repeats until b == 0
    int q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

int modInverse(int b, int m) {                   // returns b^(-1) (mod m)
  int x, y;
  int d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return mod(x, m);
}

const int MAX_N = 100010;
const int p = 1e9+7;                             // p is a prime > MAX_N

ll mod(ll a, int m) {                            // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

ll modPow(ll b, int p, int m) {                  // assume 0 <= b < m
  if (p == 0) return 1;
  ll ans = modPow(b, p/2, m);                    // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

ll inv(ll a) {                                   // Fermat's little theorem
  return modPow(a, p-2, p);                      // modPow in Section 5.8
}                                                // that runs in O(log p)

ll fact[MAX_N], invFact[MAX_N];

ll C(int n, int k) {                             // O(log p)
  if (n < k) return 0;                           // clearly
  return (((fact[n] * inv(fact[k])) % p) * inv(fact[n-k])) % p;
  // return (((fact[n] * invFact[k]) % p) * invFact[n-k]) % p; // O(1)
}

ll Fib[MAX_N], Cat[MAX_N];

fib_numbers = {}
fib_numbers[1]=1
fib_numbers[0]=0

def fib(n):
	if n==0: return 0
	if n==1: return 1
	if n==2: return 1

	if n%2==0:
		k = n//2
	else:
		k = n-1
		k = k//2

	if k in fib_numbers:
		f_k = fib_numbers[k]
	else:
		f_k = fib(k)
		fib_numbers[k] = f_k

	if k+1 in fib_numbers:
		f_k1 = fib_numbers[k+1]
	else:
		f_k1 = fib(k+1)
		fib_numbers[k+1] = f_k1


	if n%2==0: f_n = f_k*(2*f_k1 - f_k)
	else: f_n = f_k**2 + f_k1**2

	f_n = f_n%1000000000
	return f_n

P = int(input())
for x in range(P):
	K,Y = tuple(map(int,input().split()))
	print(K,fib(Y))
