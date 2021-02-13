#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	double B, Br, Bs, A, As;
	cin >> B >> Br >> Bs >> A >> As;
	
	double years = (Br-B)*Bs/As;
	if ((int) years == (int)ceil(years)) years++;
	
	//alternative without if: cout << floor( A + years +1 ) << endl;
	cout << ceil( A + years ) << endl;

	return 0;
}
