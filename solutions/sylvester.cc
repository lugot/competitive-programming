#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    long t, n, x, y, w, h;
    cin >> t;

    while(t--){
        cin >> n >> x >> y >> w >> h;
        
        for(long j=y; j<y+h; j++){
            for(long i=x; i<x+w; i++){

                int ans=1;
                long m=n, u=i, k=j;

                while(m>1){
                    //cout << "i: " << i << "j: " << j << " " << m << " " << u << " " << k << endl; 
                    if (u >= m/2 and k >= m/2) ans *= -1;
                    m /= 2;
                    u %= m, k %= m;
                }
                cout << ans << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

	return 0;
}
