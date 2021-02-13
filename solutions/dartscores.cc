#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	int P[] = {10,9,8,7,6,5,4,3,2,1};
	int n,x,y, sum=0;
	while(T--){
		cin >> n;
		sum = 0;
		while(n--){
			cin >> x >> y;	
			
			for(int &p: P){
				int radii = 20*(11-p);
				if (x*x + y*y <= radii*radii){
					sum+=p;
					break;
				}
			}	
		}
		cout << sum << endl;
	}

	return 0;
}
