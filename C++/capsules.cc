#include <bits/stdc++.h>

using namespace std;

struct cell{
	int values;
	vector<int> p;
};

int main() {
	int R,C;
	cin >> R >> C;

	int v[R*C];
	vector<vector<pair<int,int>>> inf;
	vector<vector<int>> pos;
		
	inf.capacity();


	char ca;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> ca;
			if (ca!='-') v[i*R+j]=ca-48;
		}
	}

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			inf[i*R+j].push_back(make_pair(i-1,j-1));
			inf[i*R+j].push_back(make_pair(i,j-1));
			inf[i*R+j].push_back(make_pair(i+1,j-1));
			
			inf[i*R+j].push_back(make_pair(i-1,j));
			inf[i*R+j].push_back(make_pair(i+1,j));

			inf[i*R+j].push_back(make_pair(i-1,j+1));
			inf[i*R+j].push_back(make_pair(i,j+1));
			inf[i*R+j].push_back(make_pair(i+1,j+1));
		}
	}

	int r,c,N;
	string s;
	vector<pair<int,int>> cells;

	cin >> r;
	while(r--){
		cin >> c;
		while(c--){
			cin >> N;
			cells.clear();
			for(int i=0; i<N; i++){
				cin >> s;
				int x = s[1]-48-1;
				int y = s[3]-48-1;
				cells.push_back(make_pair(x,y));
			}
			for(int i=0; i<N; i++){
				int x = cells[i].first;
				int y = cells[i].second;
				for(int j=0; j<N; j++){
					if (j==i) continue;
					int xx = cells[j].first;
					int yy = cells[j].second;
					inf[x*R+y].push_back(make_pair(xx,yy));
					for (int u=0; u<N; u++) pos[x*R+y].push_back(u);
				}
			}
		}
	}
	


	return 0;
}
