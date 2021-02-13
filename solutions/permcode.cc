#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x;
	string S,P,C;

	while(cin >> x >> S >> P >> C){

		map<char, int> revS;
		for(int i=0; i<S.length(); i++) revS[S[i]] = i;
				
		int n = C.length();
		int d = ((int)(sqrt(n*n*n) + x)) %n;

		//cout << x << S << P << C << " ";
		//cout << "d: " << d << " ";
	
		string M;
		M.assign(n, '0');

		M[d] = P[revS[C[d]]];

		int j = (d == 0 ? n-1 : d-1);
		for(; j!=d; j = (j == 0 ? n-1 : j-1)){
			M[j] = P[ revS[C[j]] ^ revS[M[(j+1) %n]] ];
		}
		cout << M << endl;
	}


	return 0;
}
