#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, a[5000], b[5000];
	
	while(true) {
		cin >> N;
		if (N==0) break;

		for (int i=0; i<N; i++) scanf("%d\n",&a[i]);
		for (int i=0; i<N; i++) scanf("%d\n",&b[i]);
		
		vector<int> va(a,a+N);
		vector<int> vb(b,b+N);

		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());

		for (int i=0; i<N; i++) {
			int index = find(va.begin(), va.end(), a[i]) - va.begin();
			printf("%d\n", vb[index]);
		}
		printf("\n");

	}

	return 0;
}
