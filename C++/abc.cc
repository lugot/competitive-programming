#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A,B,C;
	cin >> A >> B >> C;
	
	if (A>B) swap(A,B);
	if (A>C) swap(A,C);
	if (B>C) swap(B,C);
	
	vector<int> c;
	if (c.size() == 2){cout<<"ciao";}
	

	string s;
	cin >> s;
	for(auto c: s){
		if (c=='A') cout << A << " ";
		if (c=='B') cout << B << " ";
		if (c=='C') cout << C << " ";
	}
	cout << endl;

	return 0;
}
