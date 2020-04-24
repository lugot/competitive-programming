#include <bits/stdc++.h>

using namespace std;

int fib(int x, int k){
	if (x==0 or x==1) return 1; //base cases defined differently

	if (x%2==0){ //base case problem
		int n = (x+1)/2;
		int fn = fib(n, k), fn1 = fib(n-1, k);
		
		return ((fn*fn) + (fn1*fn1))%k;
	} else {
		int n = x/2;
		int fn = fib(n, k), fn1 = fib(n-1, k);

		return ((2*fn1+fn)*fn)%k;
	}
}

//implementation, fib def differently
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int Q;
	cin >> Q;

	while(Q--){
		int k;
		cin >> k;
		
		vector<int> fibs(k);

		for(int i=2;; i++){ //infinite cycle LOL
			int f = fib(i,k);
			
			if (fibs[f]!=0){
				cout << fibs[f] << endl;
				break;
			}
			else fibs[f]=i;
		}
	}


	return 0;
}
