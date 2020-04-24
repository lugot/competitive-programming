#include <bits/stdc++.h>

using namespace std;

int main() {
	int P;
	cin >> P;
	
	int ind,p,q;
	while(P--) {
		scanf("%d %d/%d\n",&ind,&p,&q);
		
		int offs=0, level=0;
		while(p!=1 ||  q!=1) {
			if (p>q) { //dx
				offs+= (int)pow(2,level);
				p-=q;
			} else { //sx
				q-=p;
			}
			level++;
		}
		printf("%d %d\n", ind, (int) pow(2,level) + offs);


	}

	return 0;
}
