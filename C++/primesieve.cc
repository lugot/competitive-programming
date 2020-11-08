#include<bitset>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

#include <bitset>
ll _sieve_size;
bitset<100000010> bs;
int n_primes = 0;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i=2; i <= _sieve_size; i++){
		if (bs[i]){
			for (ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
			n_primes++;
			//primes.push_back((int)i);
		}
	}
}

bool isPrime(ll N){
	return bs[N];
}

int main(){

	int n, q;
	cin >> n >> q;

	sieve(n);
	cout << n_primes << endl;
	//cout << primes.size() << endl;
	
	int x;
	while(q--){
		cin >> x;
		cout << isPrime(x) << endl;
	}

	return 0;
}
