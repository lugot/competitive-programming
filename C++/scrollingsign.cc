#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	while(n--){
		int k,w;
		cin >> k >> w;

		vector<string> msg;
		
		string s;
		while(w--){
			cin >> s;
			msg.push_back(s);
		}
		
		string ans = msg[0];

		for(int m=1; m<msg.size(); m++){
			string s = msg[m];

			int i=ans.length()-k, j=0; // qua si poteva benissimo fare anche con failure function
			while(i<ans.length() and ans.substr(i) != s.substr(0,k-j)){
				i++;
				j++;
			}

			if(i==ans.length()) ans = ans + s;
			else ans = ans + s.substr(k-j);
		}

		cout << ans.length() << endl;
	
	}

	return 0;
}
