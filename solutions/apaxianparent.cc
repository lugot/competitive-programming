#include <bits/stdc++.h>

using namespace std;

int main() {
	string S,P;
	cin >> S >> P;

	if (S[S.length()-1]=='e')
		cout << S << 'x' << P;
	else if (S[S.length()-1]=='a'|| 
			 S[S.length()-1]=='i'|| 
			 S[S.length()-1]=='o'|| 
			 S[S.length()-1]=='u')
		cout << S.substr(0,S.length()-1) << "ex" << P;
	else if (S.substr(S.length()-2,2) == "ex")
		cout << S << P;
	else
		cout << S << "ex" << P;
	printf("\n");

	cout << "ciao";


	return 0;
}
