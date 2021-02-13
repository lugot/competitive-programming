#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> b(n);
	for(auto &x: b) cin >> x;

	sort(b.begin(), b.end());

	int i=0;
	while(i!=n){

		if (i+2 < n and
			b[i+1] == b[i]+1 and
			b[i+2] == b[i+1]+1){

			cout << b[i];

			do{
				i++;
			}while(i<n and b[i] == b[i-1]+1);

			cout << "-" << b[i-1] << " ";
		}

		else{
			cout << b[i] << " ";
			i++;
		}
	}
	cout << endl;

	return 0;
}
