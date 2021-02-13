#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H;
	string s;
	cin >> H >> s;
	//while(cin >> s);

	int act = 1;
	for(int l=0; l<s.length(); l++){
		int k = act % (1<<l);
		act = (1<<(l+1)) + 2*k;
		if (s[l] == 'R') act++;
	}

	cout << (1<<(H+1)) - act << endl;

	return 0;
}
