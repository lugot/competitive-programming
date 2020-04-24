#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,Y;
	cin >> N >> Y;

	vector<int> obs(N);

	int x;
	for (int i=0; i<Y; i++) {
		cin >> x;
		obs[x]=1;
	}

	int X=0;
	for (int i=0; i<N; i++) if (obs[i]==0){
		cout << i << endl;
		X++;
	}

	cout << "Mario got " << N-X << " of the dangerous obstacles.\n";
	

	return 0;
}
