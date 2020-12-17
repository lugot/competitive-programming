#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		int C;
		cin >> C;

		int n = 1;
		vector<int> facts;
		facts.push_back(1);
		while(C--){
			int P, a;
			cin >> P >> a;

			//for(int i=1; i<=a; i++) facts.push_back((int)pow(P,i));
			facts.push_back((int)pow(P,a));	
			n *= (int)pow(P, a);
		}
		//facts.push_back(n);

		sort(facts.begin(), facts.end());

		for(auto x: facts) cout << x << " ";
		cout << endl;

		//cout << "\n\nTEST" << n << endl;

		//for(int i=1; i<=n; i++){
			//for(int j=i; j<=n; j++){
				//cout << "(" << i << "," << j << ")";
				//if (lcm(i,j) == n) cout << " *";
				//cout << endl;
			//}
		//}

		//cout << "facts\n\n\n";
		//for(int i=1; i<facts.size()-1; i++){
			//for(int j=i+1; j<facts.size(); j++){
				//cout << "(" << facts[i] << "," << facts[j] << ")";
				//if (lcm(facts[i],facts[j]) == n) cout << " *";
				//cout << endl;
			//}
		//}


		//cout << "(" << 1 << "," << n << ")";
		//if (lcm(1, n) == n) cout << " *";
		//cout << endl;
		//cout << "(" << n << "," << n << ")";
		//if (lcm(n, n) == n) cout << " *";
		//cout << endl;
	}

	return 0;
}
