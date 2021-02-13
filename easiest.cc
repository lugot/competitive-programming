#include <bits/stdc++.h>

using namespace std;
int sumc (int n);

int main() {
	int N;

	while(1) {
		cin >> N;
		if (N==0) break;
		
		int sumofn = sumc(N);
		
		int p=11;
		while(sumc(N*p) != sumofn) p++;
		
		//this is a comment
		cout << p << '\n';
	}


	return 0;
}

int sumc (int n) {
	int sum=0;

	while(n>0) {
		sum += n%10;
		n/=10;
	}


	return sum;
}
