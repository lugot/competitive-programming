#include <bits/stdc++.h>
#include <algorithm>    // std::max

using namespace std;

int main() {
	int N;
	string answ;

	cin >> N >> answ;

	string a,b,c;
	for (int i=0; i<N/3+3; i++) {
		a+="ABC";
		b+="BABC";
		c+="CCAABB";
	}

	int na=0, nb=0, nc=0;
	for (int i=0; i<N; i++) {
		if (answ.at(i) == a.at(i)) na++;
		if (answ.at(i) == b.at(i)) nb++;
		if (answ.at(i) == c.at(i)) nc++;
	}

	int max_score;
	max_score = max(na,nb);
	max_score = max(max_score,nc);

	cout << max_score << endl;
	if (na == max_score) cout << "Adrian" << endl; 
	if (nb == max_score) cout << "Bruno" << endl; 
	if (nc == max_score) cout << "Goran" << endl; 

	return 0;
}
