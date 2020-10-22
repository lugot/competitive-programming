#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool prime(int x){
	for(int i=2; i*i<x; i++){
		if (x %i == 0) return false;
	}
	return true;
}

int hamming(int n, int m){
	string a = to_string(n),
		   b = to_string(m);

	int dist = 0;
	for(int i=0; i<a.length(); i++){
		if (a[i] != b[i]) dist++;
	}
	return dist;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> primes;
	primes.reserve(1075);

	int num_primes = 0;
	for(int x=1000; x<9999; x++){ // can be skipped if hardcoded
		if (prime(x)){
			num_primes++;
			primes.push_back(x);
			//cout << x << endl;
		}
	}
	//cout << num_primes << endl; they are 1075

	map<int, vector<int>> adlist;

	for(int i=0; i<primes.size(); i++) for(int j=0; j<primes.size(); j++){
		if (i==j) continue;
		if (hamming(primes[i], primes[j]) == 1){
			adlist[primes[i]].push_back(primes[j]);
			adlist[primes[j]].push_back(primes[i]);
		}
	}

	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;

		if (a == b){
			cout << 0 << endl;
			continue;
		}

		map<int, int> visited;
		//queue<pair<int, int>> q;
		priority_queue<pair<int, int>> q;

		q.push({0, a});
		visited[a] = 1;
		bool found = false;
		while(!q.empty()){
			int x = q.top().second, front = -q.top().first; q.pop();
			//int x = q.front().first, front = q.front().second; q.pop();

			//cout << x << " " << front << endl;

			for(int prime: adlist[x]){
				if (visited[prime]) continue;

				if (prime == b){
					cout << front+1 << endl;
					found = true;
					while(!q.empty()) q.pop();
					break;
				}

				visited[prime] = 1;
				q.push({-(front+1), prime});
				//q.push({prime, front+1});
			}
		}
		
		if (!found) cout << "Impossible" << endl;
	}

	return 0;
}
