#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,t;
	cin >> n;
	vector<int> temp;
	
	while(cin >> t) temp.pb(t);
		
	t = 40*3;
	int d=0;
	for(int i=0; i<n-2; i++){
		if (max(temp[i], temp[i+2]) < t){
			t = max(temp[i], temp[i+2]);
			d = i;
		}
	}
	t = max(temp[d], temp[d+2]);
	printf("%d %d\n", d+1, t);

	return 0;
}
