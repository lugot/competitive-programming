#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int C;
	cin >> C;
	
	for(int c=1; c<=C; c++){
		cout << "Case #" << c << ": ";

		int N, T;
		cin >> N >> T;
		T--;
		int E;
		cin >> E;

		vector<int> emp(N, 0);
		vector<vector<int>> cars(N);

		int H, P;
		for(int i=0; i<E; i++){
			cin >> H >> P;
			emp[H-1]++;
			cars[H-1].push_back(P);
		}

		for(auto &x: cars) sort(x.begin(), x.end(), greater<int>());

		bool skip = false;
		for(int i=0; i<N; i++){
			if (i == T) continue;
			int sum = accumulate(cars[i].begin(), cars[i].end(), 0);

			if (sum < emp[i]){
				cout << "IMPOSSIBLE" << endl;
				skip = true;
				break;
			}
		}
		if (skip) continue;

		vector<int> ans(N, 0);
		for(int i=0; i<N; i++){
			if (i == T) continue;

			int acc = 0;
			int j = 0;
			while(acc < emp[i]) acc += cars[i][j++];

			ans[i] = j;
		}

		for(auto x: ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}
