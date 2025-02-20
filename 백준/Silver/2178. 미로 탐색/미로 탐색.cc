#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
vector<vector<int>> grid;
vector<pair<int, int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
int mindis=-1;
void bfs(){
    queue<pair<int, int>> q;
    q.push({0,0});

    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        if(x==N-1 && y==M-1) {
            cout<< grid[x][y];
            return;
        }
        
        for(auto [dx, dy]: dir){
            int nx = x+dx, ny=y+dy;

            if(nx>=0 && nx<N && ny>=0 && ny<M && grid[nx][ny]==1){
                q.push({nx,ny});
                grid[nx][ny] = grid[x][y]+1; // 거리 업데이트
            }
        }

        /* code */
    }
}
int main() {
    cin >> N >>M;
     grid.assign(N,vector<int>(M));

    for(int i=0; i<N; i++){
        string row;
        cin >>row;
        for(int j=0; j<M; j++){
           grid[i][j] = row[j]-'0';
        }
    }
    if(grid[0][0]==0 && grid[N-1][M-1]==0) return -1;
   bfs();
    



    return 0;
}
