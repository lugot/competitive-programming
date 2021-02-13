#include <bits/stdc++.h>

using namespace std;

int F(int n);
int g(int n);

int F(int n){
	if (n==0) return 1;
	if (n==1) return 0;
	if (n==2) return 3;
	else return F(n-2) + 2*g(n-1);
}

int g(int n){
	if (n<=0) return 0;
	if (n==1) return 1;
	else return F(n-1) + g(n-2);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> ans;
	for(int i=0; i<31; i++) ans.push_back(F(i));

	int n;
	while(cin >> n){
		if(n==-1) break;

		cout << ans[n] << endl;
	}

	return 0;
}
