#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1,  0,  1};
int dy[] = {0, 1, 1,  1,  0, -1, -1, -1};

void floodfill(int x, int y, int color, vector<vector<char>> &board){
	board[x][y] = '0' + color;
	int R = board.size(), C = board[0].size();

	for(int i=0; i<8; i++){
		int r = x+dx[i], c = y+dy[i];
		if (r >= 0 and r < R and c >= 0 and c < C and board[r][c] == '#')
			floodfill(r, c, color, board);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<vector<char>> board(m, vector<char>(n, '.'));

	string s;
	for(int i=0; i<m; i++){
		cin >> s;
		for(int j=0; j<n; j++) board[i][j] = s[j];
	}

	//for(auto v: board){
		//for(char c: v) cout << c;
		//cout << endl;
	//}

	int ans = 0;
	for(int i=0; i<m; i++) for(int j=0; j<n; j++){
		if (board[i][j] == '#') floodfill(i, j, ans++, board);
	}
	//for(auto v: board){
		//for(char c: v) cout << c;
		//cout << endl;
	//}

	cout << ans << endl;


	return 0;
}
