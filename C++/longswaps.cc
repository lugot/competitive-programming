#include <bits/stdc++.h>

using namespace std;

void swap(char *a, char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int k;
	cin >> s >> k;

	string sorted(s);
	sort(sorted.begin(), sorted.end());


	cout << s << endl;

	return 0;
}
