#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<double> side(35);

    side[0] = pow(2.0, -1.0*3/4);
    side[1] = pow(2.0, -1.0*5/4);
    for(int i=2; i<=32; i++) side[i] = side[i-2]/2;
    
    //for(int i=0; i<32; i++) cout << "i:" << i << " " << side[i] << endl;

    int n;
    cin >> n;
    
    vector<int> p, s(n);
    int x;
    while(cin >> x) p.push_back(x);
    
    double ans = 0.0;
    int needed = 2;
    for(int i=0; i<n; i++){
        
        bool exit = false;
        if (needed <= p[i]) exit = true;
            
        ans += needed/2*side[i];
        needed = 2*(needed - p[i]);
        
        if (exit){
			cout << fixed;
			cout.precision(9);
            cout << ans << endl;
            return 0;
        }
    }

    cout << "impossible\n";

    return 0;
}

