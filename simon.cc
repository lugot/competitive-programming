#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	string u;
	getline(cin, u);
	T = stoi(u);

	while(T--){
		string s;
		getline(cin, s);

		if (s.substr(0, 10) == "simon says")
			cout << s.substr(11) << endl;
		else
			cout << endl;
	}


	return 0;
}
