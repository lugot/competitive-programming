#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> entry, exit;
	unordered_map<int, int> diff;

	int x;
	while(N--){
		cin >> x;
		entry.push_back(x);
	}
	while(M--){
		cin >> x;
		exit.push_back(x);
	}

	for(int en: entry) for(int ex: exit){
		if (ex-en >= 0) diff[ex-en]++;
		//diff[abs(ex-en)]++;
	}

	int max_diff = 1e9;
	int max_occ = 0;
	for(auto e: diff){
		//cout << "occ: " << e.second << " diff: " << e.first << endl;
		if (max_occ <= e.second){
			max_occ = e.second;
			max_diff = min(max_diff, e.first);
		}
	}

	if (max_diff == 1e9) cout << 0 << endl;
	else cout << max_diff << endl;


	return 0;
}
