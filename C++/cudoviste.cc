#include <bits/stdc++.h>

// ciaone 

using namespace std;

int main() {
	int R,C;
	cin >> R >> C;
	
	char **city = new char*[R];
	for (int i=0; i<R; i++) city[i] = new char[C];
	
	string s;
	for (int i=0; i<R; i++) {
		cin >> s;
		for (int j=0; j<C; j++) {
			city[i][j] = (char)s[j];
		}
	}
	
	int smash[5];
	bzero(smash,5*sizeof(int));

	for (int i=0; i<R-1; i++) {
		for (int j=0; j<C-1; j++) {
			if (city[i][j] == '#' ||
				city[i+1][j] == '#' ||
				city[i][j+1] == '#' ||
				city[i+1][j+1] == '#')
				continue;

			int car = 0;
			if (city[i][j] == 'X') car++;
			if (city[i+1][j] == 'X') car++;
			if (city[i][j+1] == 'X') car++;
			if (city[i+1][j+1] == 'X') car++;
		
			smash[car]++;
		}
	}
	
	for (int i=0; i<5; i++) printf("%d\n",smash[i]);

	return 0;
}
