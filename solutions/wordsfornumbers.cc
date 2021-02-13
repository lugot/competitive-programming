#include <bits/stdc++.h>

using namespace std;

bool isnum(char c){
	if (c >= '0' and c <= '9') return true;
	return false;
}

string rep1(char c){
	if (c=='0') return "zero";
	if (c=='1') return "one";
	if (c=='2') return "two";
	if (c=='3') return "three";
	if (c=='4') return "four";
	if (c=='5') return "five";
	if (c=='6') return "six";
	if (c=='7') return "seven";
	if (c=='8') return "eight";
	if (c=='9') return "nine";
	return "";
}

string rep2(char c){
	if (c=='0') return "zero";
	if (c=='1') return "one";
	if (c=='2') return "two";
	if (c=='3') return "three";
	if (c=='4') return "four";
	if (c=='5') return "five";
	if (c=='6') return "six";
	if (c=='7') return "seven";
	if (c=='8') return "eight";
	if (c=='9') return "nine";
	return "";

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	while(getline(cin,s)){

		for(int i=0; i<s.length(); i++){
			if (isnum(s[i])){
				string before = s.substr(0,i);
		
				int le;
				if (i+1<s.length() and isnum(s[i+1])) le = 2;
				else le = 1;
				string after = s.substr(i+le);
				
				if (le == 1) 
					s = before + rep1(s[i]) + after;
				else if (le == 2 and s[i+1]!='0')
					s = before + rep1(s[i]) + "ty-" + rep1(s[i+1]) + after;
				else if (le == 2 and s[i+1]=='0'){
					s = before + rep1(s[i]) + "ty" + after;
				}
			}
		}






		cout << s << endl;
	}





	return 0;
}
