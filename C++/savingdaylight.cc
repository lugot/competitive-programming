#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string month, day, year;
	while(cin >> month){
		cin >> day >> year;

		string time1, time2;
		cin >> time1 >> time2;

		int h1,m1,h2,m2;
		
		int pos=0;
		while(time1[pos]!=':') pos++;
		h1 = stoi(time1.substr(0,pos));
		m1 = stoi(time1.substr(pos+1));
		
		pos=0;
		while(time2[pos]!=':') pos++;
		h2 = stoi(time2.substr(0,pos));
		m2 = stoi(time2.substr(pos+1));

		int minute_delay = m2-m1;
		int hours_delay = h2-h1;

		if(minute_delay<0){
			minute_delay+=60;
			hours_delay--;
		}

		cout << month << " " << day << " " << year << " "
			 << hours_delay << " hours " << minute_delay << " minutes" << endl;

	}

	return 0;
}
