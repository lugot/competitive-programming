#include <bits/stdc++.h>

using namespace std;

//ciaone sdas dsadasdciasoasda sdi >= 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;

		unsigned long long c, ans=0;
		for(int i=0; i<N; i++){
			cin >> c;
			
			ans = (ans + (c%N))%N;
		}
		if (ans==0) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}
