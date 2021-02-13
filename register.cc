#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> p(20);
	for(int i=2; i<p.size(); i++) p[i]=i-1;
	
	int v;
	cin >> v; p[2]=v;
	cin >> v; p[3]=v;
	cin >> v; p[5]=v;
	cin >> v; p[7]=v;
	cin >> v; p[11]=v;
	cin >> v; p[13]=v;
	cin >> v; p[17]=v;
	cin >> v; p[19]=v;
	
	int i=2;
	for(i=2; i<20; i++)
		if (p[i]!=i-1) break;

	if (i==20){
		cout << "0\n";
		return 0;
	}

	int ans=1;
	for(i=19; i>=2; i--){
		if (i==4 or i==6 or i==8 or i==9 or i==10 or i==12 or i==14 or
				i==15 or i==16 or i==18) continue;
		ans = (ans-1)*(i) + i-p[i];
	}
	cout << ans-1 << endl;

	return 0;
}
