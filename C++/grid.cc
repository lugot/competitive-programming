#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n*m+1, vector<int>());
	int k;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<m; j++){
			k = s[j] - '0';

			int act = i*m+j;
			if (act == n*m) break;
			//cout << "i: " << i << "act: " << act << endl;

			//cout << "here" << endl;
			
			int target;
			if (i+k < n){
				target = (i+k)*m+j;
				adj[act].push_back(target);
			}

			if (i-k >= 0){
				target = (i-k)*m+j;
				adj[act].push_back(target);
			}

			if (j+k < m){
				target = i*m+j+k;
				adj[act].push_back(target);
			}

			if (j-k >= 0){
				target = i*m+j-k;
				adj[act].push_back(target);
			}
		}
	}

	//for(auto v: adj){
		//for(auto x: v) cout << x << " ";
		//cout << endl;
	//}
	vector<int> d(n*m, INF); d[0] = 0;
	queue<int> q; q.push(0);

	while (!q.empty()){
		int u = q.front(); q.pop();
		
		for (int j=0; j<adj[u].size(); j++){
			int v = adj[u][j];
			if (d[v] == INF){
				d[v] = d[u] + 1;
				q.push(v);
			} 
		} 
	}

	if (d[n*m-1] == INF) cout << -1 << endl;
	else 				 cout << d[n*m-1] << endl;

	return 0;
}
