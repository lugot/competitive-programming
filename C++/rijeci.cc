#include <bits/stdc++.h>

using namespace std;

int main() {
	int K;
	cin >> K;

	int a=1, b=0;
	for (int i=0; i<K; i++) {
		int atob = a;
		a = b;
		b = b + atob;
	}

	printf("%d %d\n",a,b);


	return 0;
}
