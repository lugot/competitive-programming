#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct plat{
    double y, x1, x2;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;

    vector<plat> plats;
    int Y, X1, X2;
    for(int i=0; i<N; i++){
        cin >> Y >> X1 >> X2;
        plats.push_back({Y, X1, X2});
    }
    plats.push_back({0, 0, 100000});

    sort(plats.rbegin(), plats.rend(), 
            [](plat p1, plat p2){ return p1.y < p2.y; });

    int ans = 0;
    for(int i=0; i<N; i++){
        auto [y, x1, x2] = plats[i];
        x1 += 0.5;
        x2 -= 0.5;


        for(int j=i+1; j<N+1; j++){
            if (plats[j].x1 <= x1 and x1 <= plats[j].x2){
                ans += (y - plats[j].y);
                break;
            }
        }
        for(int j=i+1; j<N+1; j++){
            if (plats[j].x1 <= x2 and x2 <= plats[j].x2){
                ans += (y - plats[j].y);
                break;
            }
        }
    }

    cout << ans << endl;

	return 0;
}
