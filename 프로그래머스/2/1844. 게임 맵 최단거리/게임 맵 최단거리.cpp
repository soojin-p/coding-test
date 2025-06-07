#include<vector>
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m;
int min_val=INT_MAX;

void bfs(vector<vector<int> > &maps, vector<vector<bool>> &visited){
  
    }

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m= maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    
    queue<tuple<int, int, int>> q;
    q.push({0,0,1});
    visited[0][0] =true;
    while(!q.empty()){
        auto [x,y,cnt] = q.front(); q.pop();
        if(x==n-1 && y== m-1) {
            return cnt;
            
        }
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m && maps[nx][ny] !=0
              && !visited[nx][ny]){
                    q.push({nx, ny,cnt+1});
                    visited[nx][ny] =true;
                }
            }
        }
    
    
    //cout<< min_val;
    return -1;
}