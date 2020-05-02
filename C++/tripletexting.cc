#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s, ans;
	cin >> s;

	int n = s.length()/3;
	for(int i=0; i<n; i++){
		if (s[i] == s[i+n]) ans = ans + s[i];
		else if (s[i] == s[i+2*n]) ans = ans + s[i];
		else if (s[i+n] == s[i+2*n]) ans = ans + s[i+n];
	}

	cout << ans << endl;

	return 0;
}
