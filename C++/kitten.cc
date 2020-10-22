#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;

	vector<int> parent(101, -1);
	int a, b;
	while(true){
		cin >> a;
		if (a == -1) break;

		if (parent[a] == -1) parent[a] = 0;

		while(cin.peek() != '\n'){
			cin >> b;
			parent[b] = a;
		}
	}

	cout << K << " ";
	while(parent[K] != 0){
		cout << parent[K] << " ";
		K = parent[K];
	}
	cout << endl;

	return 0;
}
///////////////////////////////////////////////////////////////////////////////
