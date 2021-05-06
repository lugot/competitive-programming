#include<bits/stdc++.h>

using namespace std;


typedef int wtype;

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;

typedef vector<int> vi;
typedef vector<vi> parent;

typedef vector<wtype> vw;
typedef vector<vw> adjmatrix;
int INF = 1e9;

int n, m;
adjmatrix amatrix;
vi visited;

void floyd_warshall() {
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (amatrix[i][j] > amatrix[i][k] + amatrix[k][j] && amatrix[i][k] < INF && amatrix[k][j] < INF)
                    amatrix[i][j] = amatrix[i][k] + amatrix[k][j];
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; amatrix[i][j] != -INF && k<n; k++)
                if (amatrix[k][k] < 0 && amatrix[i][k] != INF && amatrix[k][j] != INF)
                    amatrix[i][j] = -INF;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    amatrix = adjmatrix(n, vw(n, INF));
    for (int i=0; i<n; i++) amatrix[i][i] = 0;

    return 0;
}
