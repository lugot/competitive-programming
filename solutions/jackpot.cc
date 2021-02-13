#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b==0 ? a : gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--){
		int w;
		cin >> w;

		vector<ll> m(w);
		for(auto &x: m) cin >> x;


		bool more = false;
		for(int i=1; i<w; i++){
			m[i] = lcm(m[i], m[i-1]);
			if (m[i] > 1000000000){
				more = true;
				break;
			}
		}

		if (more) cout << "More than a billion." << endl;
		else cout << m[w-1] << endl;
	}

	return 0;
}
