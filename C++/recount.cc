#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_map<string, int> ms;
	string s;

	while(true){
		getline(cin,s);
		if (s.compare("***") == 0) break;
		ms[s]++;	
	}

	string winner = ms.begin()->first;
	int max_votes=0;
	bool runoff=false;
	for(auto x: ms){
		
		//cout << x.first << " " << x.second << endl;

		if (x.second == max_votes) runoff=true;
		if (x.second > max_votes){
			max_votes = x.second;
			winner = x.first;
			runoff=false;
		}
		
	}

	if (runoff) cout << "Runoff!\n";
	else cout << winner << endl;

	return 0;
}
