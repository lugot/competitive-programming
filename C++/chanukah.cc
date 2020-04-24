#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int P;
	cin >> P;

	while(P--){
		int K,N;
		cin >> K >> N;

		cout << K << " " << N*(N+1)/2+N << endl;
	}


	return 0;
}
