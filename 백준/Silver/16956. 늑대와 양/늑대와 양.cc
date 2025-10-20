#include <stdio.h>
#include <bits/stdc++.h>


/*
접근방법:
    wolf인접한 공간에 ship이 있으면, fail
*/
using namespace std;
int R,C; //목장의 크기
char farm[501][501];

queue<pair<int,int>> wolf;
int dx[4] ={-1,1,0,0};
int dy[4] = {0,0,-1,1};


int main() {
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ans =1;
    cin>> R>>C;
    for(int r=0; r<R; ++r){
        for(int c=0; c<C; ++c){
            cin>>farm[r][c];
            if(farm[r][c]=='W'){
                wolf.push({r,c});
            }
        }
    }

    while(!wolf.empty()){
        auto [curx, cury] = wolf.front();
        wolf.pop();

        for(int i=0; i<4; i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];

            if(nx<0 || nx>=R || ny<0 || ny>=C)continue;
            if(farm[nx][ny]=='S'){
                ans =0; cout<<ans;
                return 0;
            }   
        }
    }
    for(int r=0; r<R; ++r){
        for(int c=0; c<C; ++c){
             if(farm[r][c]!='W') continue;
            
            for(int i=0; i<4; i++){
            int nr = r+dx[i];
            int nc = c+dy[i];

            if(nr<0 || nr>=R || nc<0 || nc>=C)continue;
            if(farm[nr][nc]=='.'){
               farm[nr][nc]='D';
                } 
            }
        }
    }
    cout<<ans>>"\n";
     cout << 1 << '\n';
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) cout << farm[r][c];
        cout << '\n';
    }
    return 0;
}
