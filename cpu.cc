#include <bits/stdc++.h>

using namespace std;

bool is_exploding(int n) {
    vector<int> factors;
    factors.push_back(1);
    
    //if (n % 2 == 0  and (n/2) % 2 == 0) return false;
    //if (n % 2 == 0) {
        //factors.push_back(2);
        //n /= 2;
    //}
    
    for (int i=2; i<=sqrt(n); i++) {  

        bool distinct = true;
        while (n % i == 0) {  
            if (!distinct) return false;
            factors.push_back(i);

            distinct = false;
            n = n/i;  
        }  
    }  
    factors.push_back(n);

    if (factors.size() < 4) return false;

    int i = factors.size()-1;
    int act = factors[i];
    int next = factors[i-1];

    int A = act / next;
    int B = act % next;
    while (i >= 2) {
        act = factors[i];
        next = factors[i-1];
        i--;

        if (A != act / next) return false;
        if (B != act % next) return false;
    }
    if (next != A+B) return false;


    return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        int xL, xH;
        cin >> xL >> xH;

        for (int i=xL; i<=xH; i++) {
            if (is_exploding(i)) cout << i << endl;
        }
    }

	return 0;
}
