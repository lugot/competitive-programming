#include <bits/stdc++.h>

using namespace std;

int main() {
	int rad,N;
	string col;
	string s1,s2;
	
	priority_queue<pair<int,string>> pq;

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> s1 >> s2;
		bool num_first = false;

		for (int j=0; j<s1.size() && num_first==false; j++) {
			if (s1.at(j) >= 48 && s1.at(j) <= 57) { // parsable
				string s3 = s1;
				s1 = s2;
				s2 = s3;
				num_first = true;
			}
		}

		int num = stoi(s2,nullptr,10);
		if (num_first == true) num/=2;
		
		pq.push(make_pair(num,s1));
	}
	
	string print;
	while(!pq.empty()) {
		print = pq.top().second + '\n' + print;
		pq.pop();
	}

	cout << print;


	return 0;
}
