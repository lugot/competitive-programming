#include <bits/stdc++.h>
#include <ostream>

using namespace std;
typedef pair<int, int> pi;

struct cell{
    char c;
    bool near_trap;
    bool safe;

    friend ostream& operator<<(ostream& os, const struct cell &c){
        os << c.c;
        return os;
    }
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int dirx[] = {1,0,-1,0}, diry[] = {0,1,0,-1};

    int W, H;
    cin >> W >> H;

    cell board[H][W];

    pi P;
    vector<pair<int, int>> G;

    char c;
    for(int i=0; i<H; i++) for(int j=0; j<W; j++){
        cin >> c;
        board[i][j] = {c, false, false};
        
        if (c =='P'){
            P.first = i;
            P.second = j;
        }
        if (c == 'T'){
            for(int k=0; k<4; k++){
                int x = j + dirx[k], y = i + diry[k];
                if (x<0 or y<0 or x>=W or y>=H) continue;
                
                board[x][y].near_trap = true;
            }
        }
    }

    int score = 0;
    int visited[H][W];
    bzero(&visited, H*W*sizeof(int));


    queue<pair<int, int>> q;
    q.push(P);

    while(!q.empty()){
        pi act = q.front(); q.pop();
        visited[act.first][act.second] = 1;

        for(int k=0; k<4; k++){
            int x = act.second + dirx[k], y = act.first + diry[k];
            if (x<0 or y<0 or x>=W or y>=H) continue;
            if (visited[x][y]) continue;

            if (board[x][y].c == '.' and !board[x][y].near_trap){
                q.push({x,y});
                visited[x][y] = 1;
            }
            if (board[x][y].c == 'G' and !board[x][y].near_trap){
                score++;
                board[x][y].c = '.';
                q.push({x,y});
                visited[x][y] = 1;
            }
            if (board[x][y].c == 'G' and board[x][y].near_trap){
                score++;
                board[x][y].c = '.';
            }
        }
    }
    cout << score << endl;

	return 0;
}
