#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long n,V;
	cin >> n >> V;

	long l,w,h, v=0;
	while(n--){
		cin >> l >> w >> h;

		v = max(v, l*w*h);
	}
	
	long d = v-V;

	cout << d << endl;


	return 0;
}
