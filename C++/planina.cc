#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	int i=1;
	while(N--) i*=2;
	i++;

	cout << i*i << endl;


	return 0;
}
