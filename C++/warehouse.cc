#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	while(T--){
		int N;
		cin >> N;

		map<string, int> m;

		string s;
		int qt;
		while(N--){
			cin >> s >> qt;
			m[s]+=qt;
		}
		
		map<int, vector<string>> o;
		for(auto x: m) o[x.second].push_back(x.first);
		
		cout << m.size() << endl;
		for(auto x = o.rbegin(); x!=o.rend(); x++){
			vector<string> strings = (*x).second; 
			sort(strings.begin(), strings.end());
			for (string &s: strings) cout << s << " " << (*x).first << endl;
		}

	}

	return 0;
}
