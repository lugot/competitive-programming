#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int P,D;
	cin >> P >> D;
	
	int a_votes[D], b_votes[D], d, a, b;
	bzero(a_votes, D*sizeof(int));
	bzero(b_votes, D*sizeof(int));
	while(cin >> d >> a >> b){
		a_votes[d-1]+=a;
		b_votes[d-1]+=b;
	}

	int wasted_a=0, wasted_b=0, V=0;
	for(int i=0; i<D; i++){
		if (a_votes[i] > b_votes[i]){
			printf("A %d %d\n", a_votes[i] - ((a_votes[i]+b_votes[i])/2 +1), b_votes[i]);
			wasted_a += a_votes[i] - ((a_votes[i]+b_votes[i])/2 +1); 
			wasted_b += b_votes[i];
		} else {
			printf("B %d %d\n", a_votes[i], b_votes[i] - ((a_votes[i]+b_votes[i])/2 +1));
			wasted_a += a_votes[i];
			wasted_b += b_votes[i] - ((a_votes[i]+b_votes[i])/2 +1); 
		}
		V += a_votes[i] + b_votes[i];
	}

	printf("%.6lf\n", abs(wasted_a - wasted_b + 0.0) / V);

	return 0;
}
