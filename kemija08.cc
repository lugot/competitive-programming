#include <bits/stdc++.h>

using namespace std;

int main() {
	string in,out;
	getline(cin, in);

	for (int i=0; i<in.length(); i++) {
		out.append(1,in.at(i));
		if (in.at(i) == 'a' || 
		    in.at(i) == 'e' || 
	        in.at(i) == 'i' || 
		    in.at(i) == 'o' || 
		    in.at(i) == 'u') i+=2; 
	}

	cout << out << endl;


	return 0;
}
