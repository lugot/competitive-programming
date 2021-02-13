#include <bits/stdc++.h>

using namespace std;

int win(string s) {
	for(int i=0; i<s.length(); i++)
		if (s.at(i) != '-') return 0;
	

	return 1;
}

int main() {
	string word,alp;
	cin >> word >> alp;
	
	int cur_let=0,  hang=0, found=0;

	for (int i=0; i<26; i++) {	
		char let = alp[i];
		
		found=0;
		for (int j=0; j<word.length(); j++)
			if (word[j] == let) { 
				found=1;
				word[j]='-';
			}
		if (win(word)) break;
			
		if (!found) hang++;
		if (hang==10) {
			cout << "LOSE\n";
			return 0;
		}

	}
	cout << "WIN\n";
	return 0;
}
