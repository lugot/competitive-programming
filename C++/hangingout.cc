#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {

	int L,x, n=0;
	cin >> L >> x;


	int group_size, act_capacity=0;
	string s;
	for (int i=0; i<x; i++) {
		cin >> s >> group_size;


		if (!s.compare("enter")) {
			if (act_capacity + group_size > L) n++;
			else act_capacity += group_size;
		} else act_capacity -= group_size;
	}

	cout << n << '\n';


	return 0;
}
