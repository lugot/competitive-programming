#include <bits/stdc++.h>

using namespace std;

int ciaone(int j){
	return 1;
}


int main() {
	int R,C;
	cin >> R >> C;

	char grid[21][21];
	bzero(grid,21*21);

	string line;
	for(int i=0; i<R; i++) {
		cin >> line;
		for (int j=0; j<C; j++) grid[i][j] = line[j];	
	}

	list<string> v;
	for (int i=0; i<R; i++) 
	{
		string s = grid[i];
	
		int init=-1;
		for (int i=0; i<s.length(); i++) {
			if (s[i] == '#') {
				init=-1;
				continue;
			}
			if (init==-1 && s[i]!='#') init=i;

			if (init!=-1 && (s[i+1] == '#' || i+1 == s.length()) && i-init+1>=2) {
				v.push_back(s.substr(init, i-init+1));
				init=-1;
			}
		}
	}

	char grids[21][21];
	bzero(grids,21*21);

	for(int i=0; i<C; i++)
		for(int j=0; j<R; j++) grids[i][j] = grid[j][i];
	
	for (int i=0; i<C; i++) 
	{
		string s = grids[i];
		
		int init=-1;
		for (int i=0; i<s.length(); i++) {
			if (s[i] == '#') {
				init=-1;
				continue;
			}
			if (init==-1 && s[i]!='#') init=i;

			if (init!=-1 && (s[i+1] == '#' || i+1 == s.length()) && i-init+1>=2) {
				v.push_back(s.substr(init, i-init+1));
				init=-1;
			}
		}
	}
	
	v.sort();
	cout << v.front() << endl;


	return 0;
}
