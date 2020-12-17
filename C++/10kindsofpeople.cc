#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int m[1000][1000], r, c;

void floodfill(int i, int j, int value, int mark) {
    m[i][j] = mark;

    if (i+1 < r  && m[i+1][j] == value) floodfill(i+1, j, value, mark);
    if (i-1 >= 0 && m[i-1][j] == value) floodfill(i-1, j, value, mark);
    if (j+1 < c  && m[i][j+1] == value) floodfill(i, j+1, value, mark);
    if (j-1 >= 0 && m[i][j-1] == value) floodfill(i, j-1, value, mark);
	
	return;
}
	
int main() {
	// int r,c;
	cin >> r >> c;
		
    for (int i = 0; i < r; i++) {
		int j = 0;
            
		string s;
		cin >> s;

		
		for(char c: s) m[i][j++] = c-'0';
	}


	//si poteva usare anche unionfind per le queries, il principio è lo stesso
	// e probabilmente era anche più veloce, altrimenti l'algoritmo
	// hoshen-kopelman
	int odd=3, even=2;
	for(int i=0; i<r; i++){

			for(int j=0; j<c; j++){
			if (m[i][j] == 0){
				floodfill(i, j, 0, even);
				even+=2;
			}
			if (m[i][j] == 1){
				floodfill(i, j, 1, odd);
				odd+=2;
			}
		}
	}
		
	int n;
	cin >> n;

    
	while(n--){
		int r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		
		r1--; c1--; r2--; c2--;

		if (m[r1][c1] == m[r2][c2]){
			if (m[r1][c1]%2==0) cout << "binary\n";
			else cout << "decimal\n";
		}
		else cout << "neither\n";


	}

	return 0;
}
