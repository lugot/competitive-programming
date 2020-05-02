#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string ciph, key, msg;
	cin >> ciph >> key;
	int m = key.length();

	key = key + string(ciph.length(), '*');
	msg = string(ciph.length(), '*');

	for(int i=0; i<ciph.length(); i++){
		msg[i] = ciph[i] - key[i];
		if (msg[i]<0) msg[i] += 26;
		msg[i] += 65;
	
		key[i+m] = msg[i];
	}

	cout << msg << endl;

	return 0;
}
