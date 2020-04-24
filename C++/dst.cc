#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	while(N--){
		char c;
		int D,H,M;
		cin >> c >> D >> H >> M;

		if (c=='F') M+=D;
		else M-=D;

		while(M>=60){
			M -= 60;
			H++;
		}
		while(M<0){
			M += 60;
			H--;
		}

		if (H<0) H+=24;
		H %=24;

		cout << H << " " << M << endl;

	}

	return 0;
}
