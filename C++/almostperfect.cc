#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int d;
	while(cin >> d){
		vector<int> div = {1};
		
		// sqrt(n) divisors
		int sum = 1;
		for(int i=2; i<=sqrt(d); i++){
			if (d%i == 0){
				if (d/i == i) sum += i;
				else sum += i + d/i;
			}
		}
		
		cout << d;
		if (d == sum) cout << " perfect\n";
		else if (abs(d-sum) <= 2) cout << " almost perfect\n";
		else cout << " not perfect\n";
	}

	return 0;
}
