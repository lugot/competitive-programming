#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	unordered_map<string, int> kattis, domjudge;
	
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		
		//if (kattis.find(s) == kattis.end()) kattis[s]=0;
		kattis[s]++;
	}

	for(int i=0; i<n; i++){
		cin >> s;
		
		//if (domjudge.find(s) == domjudge.end()) domjudge[s]=0;
		domjudge[s]++;
	}
	
	int ans=0;
	for(auto sub: kattis) ans += min( sub.second, domjudge[sub.first]);
	cout << ans << endl;

	return 0;
}
