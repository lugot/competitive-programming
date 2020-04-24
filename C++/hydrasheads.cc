#include <bits/stdc++.h>
#include<unistd.h>

using namespace std;

int main() {
	int H,T,S;
	
	while(1) {
		cin >> H >> T;
		if (H == 0 && T == 0) return 0;
		S=0;

		while (!(H == 0 && T == 0)) {
			
			if (H>=2) {
				H-=2;
				S++;
			}
			else if (H%2 != 0 && T==0) {
				printf("-1\n");
				return 1;
			}
			else if (T==1) {
				T++;
				S++;
			}
			else if (H==1 && T>1) {
				T-=2;
				H++;
				S++;
			}
			else if (H==0 && T>1) {
				if (T== 2) {
					T++;
					S++;
				}
				else {
					T-=2;
					H++;
					S++;
				}
			}
		}
		printf("%d\n",S);
	}



	return 0;
}
