#include <bits/stdc++.h>
#define abs(x,y) ((x-y)>0 ? (x-y) : ((x-y)*-1))

using namespace std;

int main() {
	int N,Q;
	cin >> N >> Q;
	int comp[N];
	
	int pos;
	for(int i=0; i<N; i++) {
		cin >> pos;
		comp[i]=pos;
	}

	int mode,a,b;
	while(Q--) {
		cin >> mode >> a >> b;
		
		if (mode==1) comp[a-1]=b;
		else cout << abs(comp[a-1],comp[b-1]) << "\n";

	}

	return 0;
}
