#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<char>> b(4, vector<char>(4));

	char c;
	for(int i=0; i<4; i++) for(int j=0; j<4; j++)
		cin >> b[i][j];

	//for(int i=0; i<4; i++){
		//for(int j=0; j<4; j++) cout << b[i][j];
		//cout << endl;
	//}

	map<char, pair<int, int>> m;
	m['A'] = {0,0};
	m['B'] = {0,1};
	m['C'] = {0,2};
	m['D'] = {0,3};
	m['E'] = {1,0};
	m['F'] = {1,1};
	m['G'] = {1,2};
	m['H'] = {1,3};
	m['I'] = {2,0};
	m['J'] = {2,1};
	m['K'] = {2,2};
	m['L'] = {2,3};
	m['M'] = {3,0};
	m['N'] = {3,1};
	m['O'] = {3,2};


	int ans = 0;
	for(int i=0; i<4; i++) for(int j=0; j<4; j++){
		char c = b[i][j];
		if (c == '.') continue;
		ans += abs(m[c].first - i) + abs(m[c].second - j);
	}

	cout << ans << endl;

	return 0;
}
