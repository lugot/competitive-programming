#include <bits/stdc++.h>

using namespace std;

struct state{
	int done;
	vector<int> poss;
};

struct choice{
	int enc;
	int ch;
	vector<state> st;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> adj(N, vector<int>(N));

	string sin;
	while(cin >> sin){
		int i=0;
		while(sin[i] != '-') i++;

		int a = stoi(sin.substr(0, i)),
			b = stoi(sin.substr(i+1, sin.length()-i-1));
		a--;
		b--;

		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	for(auto x: adj){
		for (auto y: x) cout << y;
		cout << endl;
	}

	vector<state> st(N);
	for(auto &s: st){
		s.done = -1;
		s.poss = vector<int>(4, 1);
	}

	//st[0].done = 0;
	stack<choice> s;
	s.push({0, 0, st});

	while(!s.empty()){
		auto [enclosure, animal, status] = s.top(); s.pop();

		status[enclosure].done = animal;

		bool end = true;
		for(auto state: status){
			if (state.done == -1){
				end = false;
				break;
			}
		}

		if (end){
			int i=1;
			for(auto state: status) cout << (i++) << " " << state.done+1 << endl;
			break;
		}

		for(int j=0; j<N; j++){
			if (adj[enclosure][j] == 1){
				status[j].poss[animal] = 0;
				if (status[j].poss[0] + 
				 	status[j].poss[1] + 
					status[j].poss[2] + 
					status[j].poss[3] == 1){
					
					// skip this branch, theres only a possible choice here
					if (status[j].poss[0] == 1) status[j].done = 0;
					if (status[j].poss[1] == 1) status[j].done = 1;
					if (status[j].poss[2] == 1) status[j].done = 2;
					if (status[j].poss[3] == 1) status[j].done = 3;
				}
			}
		}

		// find first enclosure and make a choice
		int firstenc = 0;



	}


	return 0;
}
