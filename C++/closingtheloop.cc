#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	int S, rope_len;
	char sel;
	string s;
	vector<int> b,r;

	for(int j=0; j<N; j++) {
		cin >> S;
		while(S--) {
			cin >> s;
			sel = s[s.length()-1];
			
			s[s.length()-1]=0;
			rope_len = atoi(s.c_str());

			if (sel=='R') r.push_back(rope_len);
			else b.push_back(rope_len);
		}

		sort(r.rbegin(), r.rend());
		sort(b.rbegin(), b.rend());

		int min = fmin(r.size(),  b.size());
		
		int tot_len=0;
		for (int i=0; i<min; i++) tot_len+= r[i] + b[i];
		tot_len -= (min)*2;
		
		tot_len = fmax(tot_len, 0); 
		cout << "Case #" << j+1 << ": " << tot_len << endl;
		b.clear(); r.clear();
	}

	return 0;
}
