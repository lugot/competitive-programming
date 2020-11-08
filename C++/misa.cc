#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, S;
	cin >> R >> S;

	vector<vector<char>> ch(R, vector<char>(S));
	for(auto &x: ch) for(auto &c: x) cin >> c;

	//for(int i=0; i<R; i++){
		//for(int j=0; j<S; j++) cout << ch[i][j];
		//cout << endl;
	//}

	int dirx[] = { 1, 1, 0, -1, -1, -1, 0,  1};
	int diry[] = { 0, 1, 1,  1,  0, -1, -1, -1};

	int max_hands = 0;
	for(int i=0; i<R; i++) for(int j=0; j<S; j++){
		int count = 0;
		if (ch[i][j] == '.') for(int r=0; r<8; r++){
			if (i+diry[r] >= 0 and i+diry[r] < R and
				j+dirx[r] >= 0 and j+dirx[r] < S){
				if (ch[i+diry[r]][j+dirx[r]] == 'o') count++;
			}
		}

		max_hands = max(max_hands, count);
	}

	int ans = 0;
	for(int i=0; i<R; i++) for(int j=0; j<S; j++){
		if (ch[i][j] == 'o') for(int r=0; r<8; r++){
			if (i+diry[r] >= 0 and i+diry[r] < R and
				j+dirx[r] >= 0 and j+dirx[r] < S){
				if (ch[i+diry[r]][j+dirx[r]] == 'o') ans++;
			}
			ch[i][j] = '.';
		}
	}

	cout << ans + max_hands << endl;

	return 0;
}
