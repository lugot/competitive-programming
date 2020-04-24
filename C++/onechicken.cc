#include <bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
	cin >> N >> M;

	string p;
	if (abs(N-M) == 1) p = "piece";
	else p = "pieces";

	if (N > M) printf("Dr. Chaz needs %d more %s of chicken!\n", N-M,p.data());
	else printf("Dr. Chaz will have %d %s of chicken left over!\n",M-N,p.c_str());

	return 0;
}
