#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    string before, after;
    cin >> before >> after;
    int n = before.length();
    int m = after.length();

    int i, j;
    i = 0;
    while (i < min(n, m) and before[i] == after[i]) i++;
    j = 0;
    while (i < min(n, m) and 
            before[before.length()-1-j] == after[after.length()-1-j]) j++;

    //cout << i-1 << " " << j-1 << endl;
    
    int ans = after.length() - i - j;
    ans = max(0, ans);
    cout << ans << endl;

	return 0;
}
