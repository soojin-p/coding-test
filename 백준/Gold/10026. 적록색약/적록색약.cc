#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 101;
int N;

vector<string> color;
vector<vector<bool>>visit;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool isSameColor(char a, char b, bool flag){
    if(flag){
        if((a=='R'|| a=='G') && (b=='R'|| b=='G')){
            return true;
        }
    }
    return a == b;
}

void dfs(int x,int y,bool flag){
    visit[y][x] = true;
    char cur = color[y][x];

    for(int i=0; i< 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0; nx <N && ny>=0 &&ny<N){
            if(!visit[ny][nx]&& isSameColor(cur,color[ny][nx],flag)){
               dfs(nx,ny,flag);
            }
        }
    }
}

int cntfun(bool flag){
    visit.assign(N,vector<bool>(N, false));
    int cnt =0;

    for(int i=0; i< N; i++){
        for(int j=0; j<N; j++){
            if(!visit[j][i]){
                dfs(i,j,flag);
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){

    cin>> N;
    color.resize(N);

    for(int i=0; i<N; i++){
        cin>> color[i];
    }
  
    int normal = cntfun(false);
    int unnormal = cntfun(true);

    cout << normal << " " << unnormal;

    return 0;
}