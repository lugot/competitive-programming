#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		string t, p, s1, s2, s3;
		cin >> t >> p >> s1 >> s2 >> s3;

		vector<string> sugg = {s1,s2,s3,p};
		
		int ans = 4000000;
		for(string s: sugg){
			int sim=0;
			
			while(t[sim] == s[sim] and sim < min(t.length(), s.length())) sim++;
			sim = t.length() + s.length() - 2*sim;
			if (s!=p) sim++;

			ans = min(ans, sim);
		}
		cout << ans << endl;
	}

	return 0;
}
