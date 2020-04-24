#include <bits/stdc++.h>

using namespace std;

int bin[1000][1000];

int binomial(int n, int k){
	if (k==n or k==0) return 1;
	int b = binomial(n-1,k-1) + binomial(n,k-1);
	if (bin[n][k]==0)
		bin[n][k]=b;
	return b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << binomial(999,596) << endl;

	return 0;
}
