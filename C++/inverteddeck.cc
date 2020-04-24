#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,v, prev;
	cin >> n;
	int a=0,b=0;
	
	vector<int> deck(n);
	for(int i=0; i<n; i++){
		cin >> v;
		deck[i]=v;
	}
	
	for(int i=1; i<n; i++)
		if (deck[i] < deck[i-1]){
			a = i;
			break;
		}
	b=a;
	
	while (a>0 and deck[a-1] >= deck[a]) a--;
	while(b<n-1 and deck[b+1] <= deck[b]) b++;
	

	for(int i=a, j=b; i<j; i++, j--){
		int temp = deck[i];
		deck[i]=deck[j];
		deck[j]=temp;
	}

	//for(auto x: deck) cout << x << " ";
	//cout << endl;

	for(int i=1; i<n; i++)
		if (deck[i] < deck[i-1]){
			cout << "impossible\n";
			return 0;
		}

	cout << a+1 << " " << b+1 << endl;
	
	return 0;
}
