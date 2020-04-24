#include <bits/stdc++.h>

using namespace std;

int main() {
	string s,alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '";
	int N;
	scanf("%d\n",&N);

	for (int i=0; i<N; i++) {
		getline(cin,s);
		int act = alp.find(s.at(0));
	
		double time=0.0;
		for (int j=1; j<s.length(); j++) {
			int next = alp.find(s.at(j));
			
			double diff = abs(next-act);
			if (diff > 14) diff = 28*(1-diff/28);
			
			time += (60*M_PI*diff/28.0)/15;
			act = next;

		}
		printf("%.6f\n",time + s.length());
	}


	return 0;
}
