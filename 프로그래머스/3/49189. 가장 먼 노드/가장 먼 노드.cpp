#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> pos(n+1);
    for(auto e: edge){
        int u =e[0], v=e[1];
        pos[u].push_back(v);
        pos[v].push_back(u);
    }
    vector<int> dist(n+1,-1);
    dist[1]=0;
   queue<int> q;
    q.push(1);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto next: pos[cur]){
            if(dist[next]==-1){
                dist[next]= dist[cur]+1;
                q.push(next);
            }
        }
    }
    
    int maxDist = *max_element(dist.begin(), dist.end());
     answer = count_if(dist.begin(), dist.end(),[&](int d){
       return d== maxDist; 
    });
    return answer;
}