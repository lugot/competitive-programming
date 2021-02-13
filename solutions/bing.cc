#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	unordered_map<string, int> m;

	string s;
	while(N--){
		cin >> s;

		cout << m[s] << endl;

		for(int i=1; i<=s.length(); i++){
			m[s.substr(0,i)]++;	
		}
	}

	return 0;
}
