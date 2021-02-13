#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string C,K;
	cin >> C >> K;

	for(int i=0; i<C.size(); i++){
		if (i%2==0){
			int x = C[i]-K[i];
			if (x<0) x+=26;
			C[i] = x+65;
		}
		if (i%2!=0) C[i] = (C[i]+K[i]-65*2)%26 +65;
	}

	cout << C << endl;

	return 0;
}
