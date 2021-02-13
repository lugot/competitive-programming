#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,d, co=2;
	vector<int> pe(n);
	pe[0]=1;

	cin >> n;
	while(cin >> d) pe[d+1]=co++;
	for(int i=0; i<n; i++) printf("%d ", pe[i]); 	
	printf("\n");	

	return 0;
}
