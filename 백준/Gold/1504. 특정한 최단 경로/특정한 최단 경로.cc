#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// 방향성이 없는 드라마

vector<pair<int, int>> graph[8001];

const int INF=1e9;

vector<int> dijkstra(int start, int n){
    vector<int>dist(n+1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<>> pq;
    dist[start]=0;
    pq.push({0,start});
    
   while (!pq.empty())
   {
     auto[cost, now] = pq.top();
     pq.pop();

     if(dist[now]<cost) continue;

     for(auto[next, w]: graph[now]){
        int next_cost = dist[now]+w;
        
        if(next_cost <dist[next]){
            dist[next]= next_cost;
            pq.push({next_cost,next});
        }
     }

    /* code */
   }
   return dist;
}

int main(){
    int N, E;
    cin >>N>> E;

    for(int i=0; i< E; i++){
        int a, b, c;
        cin >>a>>b>>c;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }
    int v1, v2;
    cin >>v1>>v2;

    vector<int> start_dist = dijkstra(1,N);
    vector<int> v1_dist = dijkstra(v1,N);
    vector<int> v2_dist = dijkstra(v2,N);

    int path1 = start_dist[v1]+ v1_dist[v2] + v2_dist[N];
    int path2 = start_dist[v2] + v2_dist[v1] + v1_dist[N];

    int result = min(path1,path2);

    if(result>=INF || v1_dist[v2]>=INF) cout<< -1;
    else cout<<result;

    return 0;

}