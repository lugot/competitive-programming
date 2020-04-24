#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int point_A=0, point_B=0;
	string s;
	cin >> s;

	for(int i=0; i<s.length(); i+=2){
		if (s[i]=='A') point_A += s[i+1]-'0';
		else point_B += s[i+1]-'0';
		
		if (point_A >= 11 && point_B <= point_A -2){
			printf("A\n");
			break;
		} else if (point_B >= 11 && point_A <= point_B -2){
			printf("B\n");
			break;
		}

	}

	return 0;
}
