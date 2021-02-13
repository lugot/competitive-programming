#include <bits/stdc++.h>
#include <map>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<char, string> notes;
	notes['c'] = "0111001111";
    notes['d'] = "0111001110";
    notes['e'] = "0111001100";
    notes['f'] = "0111001000";
    notes['g'] = "0111000000";
    notes['a'] = "0110000000";
    notes['b'] = "0100000000";
    notes['C'] = "0010000000";
    notes['D'] = "1111001110";
    notes['E'] = "1111001100";
    notes['F'] = "1111001000";
    notes['G'] = "1111000000";
    notes['A'] = "1110000000";
    notes['B'] = "1100000000";

	int t;
	cin >> t;
	cin.ignore();
	
	string s;
	while(t--){
		getline(cin, s);
		//cout << "|" << s << "|" << endl;

		string fingers = "0000000000",
			       act = "0000000000";

		for(char c: s){
			for(int i=0; i<10; i++){
				if (act[i] == '0' and notes[c][i] == '1') fingers[i]++;
			}

			act = notes[c];
		}

		for(char c: fingers) cout << c-48 << " ";
		cout << endl;
	}

	return 0;
}
