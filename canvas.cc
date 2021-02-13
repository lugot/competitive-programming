#include <bits/stdc++.h>
#include <queue>

using namespace std;

typedef long long ll;

ll f(vector<ll> c, ll a, ll b) {
    
    //cout << a << " " << b << endl;

    ll total = 0;
    for (int i=a; i<=b; i++) total += c[i];

    if (b == a) return 0;
    if (b == a+1) return total;

    ll A = 0, 
       B = total, 
       prev = abs(B-A);

    int i;
    for (i=a; i<=b; i++) {
        A += c[i];
        B -= c[i];

        if (abs(B-A) >= prev) break;
        prev = abs(B-A);
    }





    
    //cout << "i: " << i-1 << endl;
    
    ll f1 = f(c, a, i-1),
       f2 = f(c, i, b);

    return total + f1 + f2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    ll T;
    cin >> T;

    while (T--) {
        ll N;
        cin >> N;

        vector<ll> canvas(N);
        for (auto &x: canvas) cin >> x;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (auto x: canvas) pq.push(x);

        ll ans = 0;
        while (pq.size() >= 2) {
            ll A = pq.top(); pq.pop();
            ll B = pq.top(); pq.pop();

            ans += A+B;
            pq.push(A+B);
        }
        //ans += pq.top();

        cout << ans << endl;
    }

	return 0;
}
