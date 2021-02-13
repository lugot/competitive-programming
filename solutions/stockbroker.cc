#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int d;
	cin >> d;

	long long money = 100;
	int prev, now;
	cin >> prev;
	d--;

	while(d--){
		cin >> now;
		
		if (now>prev){
			long long num_stocks = (money/prev > 100000 ? 100000L : money/prev);
			money+=num_stocks*(now-prev);
		}
		prev=now;
	}

	cout << money << endl;


	return 0;
}
