#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i;
	while(cin >> i){
		if (i==1) cout << 1 << endl;
		else cout << i + i-2 << endl;
	}

	return 0;
}
