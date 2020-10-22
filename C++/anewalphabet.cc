#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> m = {"@", "8", "(" , "|)", "3", "#", "6", "[-]", "|",
		"_|", "|<", "1", "[]\134\057[]", "[]\134[]", "0", "|D", "(,)", 
		"|Z", "$", "']['", "|_|", "\134\057", "\134\057\134\057", "}{", 
		"`/", "2"};

	vector<int> a;
	a.push_back(3);
	
	string s, ans;
	getline(cin, s);

	for(auto c: s){
		if (c>=65 and c<=90) ans = ans + m[c-65];
		else if (c>=97 and c<=122) ans = ans + m[c-97];
		else ans = ans + c; 
	}

	cout << ans << endl;

	return 0;
}
