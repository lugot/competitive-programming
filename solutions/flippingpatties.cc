#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> time(43205);
	
	while(n--){
		int d,t;
		cin >> d >> t;
		
		time[t]++;
		time[t-d]++;
		time[t-d*2]++;
	}

	int maxt = 0;
	for(auto t: time) maxt = max(maxt, t);

	cout << ceil(maxt/2.0) << endl;

	return 0;
}
