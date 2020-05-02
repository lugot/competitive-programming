#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	while(cin >> n >> m){
		if (n==0 and m==0) break;
		
		vector<int> heads(n), knights(m);
		for(auto &x: heads) cin >> x;
		for(auto &x: knights) cin >> x;
		
		sort(knights.begin(), knights.end());
		sort(heads.begin(), heads.end());

		bool doomed = false;
		int ans = 0;
		for(int i=0; i<heads.size(); i++){
			if (knights.size() == 0){ //no more knights 
				cout << "Loowater is doomed!\n";
				doomed = true;
				break;
			}

			// trick here on lower bound: first elem !< so = or >
			auto it = lower_bound(knights.begin(), knights.end(), heads[i]); 
			if (it == knights.end()){ //doesnt find a knight
				cout << "Loowater is doomed!\n";
				doomed = true;
				break;
			}
			
			ans += *it;

			knights.erase(it);
		}

		if (!doomed){
			cout << ans << endl;
		}
		
	}

	return 0;
}
