#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	long double e = 1.0, fact = 1;
	for(int i=1; i<n+1; i++){
		fact*=i;
		e += 1.0/fact;	
	}
	
	cout << fixed << setprecision(15);
	cout << e << endl;

	return 0;
}
