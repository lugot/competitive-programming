#include <bits/stdc++.h>

using namespace std;

struct p{
	int x,y;
};

double d(struct p p1, struct p p2) { return sqrt( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) ); }

struct p findn(int ind, int p[3][3]) {
	int x,y;
	struct p next;
	
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if (p[i][j] == ind) {
				next.x=i;
				next.y=j;
			}
	
	return next;
}

int main() {
	int p[3][3],a;

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++) {
			cin >> a;
			p[i][j] = a;
		}

	double dst=0;
	struct p prev = findn(1, p), next;
	
	for (int i=2; i<=9; i++) {
		next = findn(i,p);
		dst+= d(next,prev);
		prev=next;
	}

	printf("%.6lf\n",dst);


	return 0;
}
