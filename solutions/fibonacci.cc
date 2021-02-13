#include <bits/stdc++.h>
#include <chrono>

using namespace std;
typedef long long L;

L fib(L x){
	if (x==0 or x==1) return 1;
	if (x%2==0){
		int n = (x+1)/2;
		int fn = fib(n), fn1 = fib(n-1);
		return ((fn*fn) + (fn1*fn1));
	}else{
		int n = x/2;
		int fn = fib(n), fn1 = fib(n-1);
		return ((2*fn1+fn)*fn);
	}
}

L h(int n){
	




}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> fib_even(26), fib_odd(26);
	fib_even[0] = fib_odd[0] = "0";
	fib_even[1] = fib_odd[0] = "1";
	for(int i=2; i<=25; i++){
		fib_even[i] = fib_even[i-1] + fib_even[i-2];
		 fib_odd[i] =  fib_odd[i-2] + fib_odd[i-1];	
	}

	int n;
	string s;
	while(cin >> n >> s){
		

		vector<L> h(n+1);




	}

	return 0;
}
