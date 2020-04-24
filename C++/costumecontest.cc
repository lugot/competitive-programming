#include <bits/stdc++.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	map<string, int> m;
	
	string s;
	while(N--){
		cin >> s;
		if (m[s] == 0) m.insert({s,0});
		m[s]++;
	}
	
	int mi = 1000;
	for(auto p: m) mi = min(mi, p.second);
	
	vector<string> sol;
	
	for(auto p: m)
		if (p.second == mi) sol.push_back(p.first);

	for(auto s: sol) cout << s << endl;
	sort(sol.begin(), sol.end());

	return 0;
}
