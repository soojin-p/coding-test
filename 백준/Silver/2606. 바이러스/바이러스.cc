#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
vector<vector<int>> grid;
vector<bool> visited;
int cnt=0;
void dfs(int node){
visited[node] = true;


for(int next : grid[node]){
    if(!visited[next]){
        cnt++;
        dfs(next);
    }   
}
}

int main() {
    cin >> N >>M;
     //grid.assign(N,vector<int>(M));
    grid.resize(N+1);
    for(int i=0; i<M; i++){
        int a,b;
        cin >>a >>b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
   visited.assign(N+1,false);
   dfs(1);
    
   cout<<cnt;



    return 0;
}
