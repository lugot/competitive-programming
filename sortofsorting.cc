#include<bits/stdc++.h>

using namespace std;

bool cmp(string s1, string s2){
	return s1.substr(0,2).compare(s2.substr(0,2)) < 0;	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while(cin >> n){
		if (n==0) break;

		vector<string> names;
		
		cout << "ciao\n;";
		cout << "ciao\n;";
		cout << "ciao\n;";
		cout << "ciao\n;";
		cout << "ciao\n;";

		string s;
		while(n--){
			cin >> s;
			names.push_back(s);
		}
	
		stable_sort(names.begin(), names.end(), cmp);

		for(auto s: names) cout << s << endl;
		cout << endl;

	}

	return 0;
}
