#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> A(n), B(n);

	for(auto &x: A) cin >> x;
	for(auto &x: B) cin >> x;


	//for(auto &x: B) cout << x << " ";

	ll sum1, sum2, sum3;
	sum1 = sum2 = sum3 = 0;
	for(int i=0; i<n; i+=3) sum1 += A[i];
	for(int i=1; i<n; i+=3) sum2 += A[i];
	for(int i=2; i<n; i+=3) sum3 += A[i];

	vector<ll> l(3, 0);

	for(int i=0; i<n; i++){
		l[(i+1)%3] += B[i]*sum1;
		l[(i+2)%3] += B[i]*sum2;
		l[i%3]     += B[i]*sum3;
	}

	cout << l[2] << " " << l[0] << " " << l[1] << endl;

	return 0;
}
