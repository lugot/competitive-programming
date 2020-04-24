#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[42];
	bzero(a,42*sizeof(int));

	for (int i=0; i<10; i++) {
		scanf("%d\n",&n);
		a[n%42]++;
	
	}

	vector<int> o;
	
	int diff=0;
	for (int i=0; i<42; i++)
		if (a[i]!=0) diff++;

	printf("%d\n",diff);


	return 0;
}
