#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string m = "0123456789ACDEFHJKLMNPRTVWX";

int ind(char c){
	return find(m.begin(), m.end(), c) - m.begin();
}

ll conv(string s){
	ll acc=1, ans=0;
	
	for(int i = s.length()-1; i>=0; i--){
		ans+= acc*(ind(s[i]));
		acc*=27;
	}

	return ans;
}

char f(string s){
	int ans;
	ans = (2*ind(s[0]) ) %27;
	ans+= (4*ind(s[1]) ) %27;
	ans+= (5*ind(s[2]) ) %27;
	ans+= (7*ind(s[3]) ) %27;
	ans+= (8*ind(s[4]) ) %27;
	ans+= (10*ind(s[5]) ) %27;
	ans+= (11*ind(s[6]) ) %27;
	ans+= (13*ind(s[7]) ) %27;
	
	return m[ ans%27 ];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int P;
	cin >> P;

	while(P--){
		int K;
		string s;
		cin >> K >> s;

		string ucn = s.substr(0,8);
		char check = s[8];
		
		for(int i=0; i<8; i++){
			if (ucn[i]=='B') ucn[i]='8';
			if (ucn[i]=='G') ucn[i]='C';
			if (ucn[i]=='I') ucn[i]='1';
			if (ucn[i]=='O') ucn[i]='0';
			if (ucn[i]=='Q') ucn[i]='0';
			if (ucn[i]=='S') ucn[i]='5';
			if (ucn[i]=='U') ucn[i]='V';
			if (ucn[i]=='Y') ucn[i]='V';
			if (ucn[i]=='Z') ucn[i]='2';
		}

		if (f(ucn) != check) cout << K << " Invalid\n";
		else cout << K << " " << conv(ucn) << endl;

	}

	return 0;
}
