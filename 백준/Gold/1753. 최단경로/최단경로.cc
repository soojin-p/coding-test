#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[20001];
vector<int> dist;

const int INF=1e9;

void dijkstra(int start){

    priority_queue<pair<int, int> , vector<pair<int, int>>,greater<>> pq;

    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        
        pq.pop();

        if(dist[now]<cost) continue;;

        for(auto[next,weight]: graph[now]){
            int newCost =dist[now] + weight;

            if(newCost<dist[next]){
                dist[next] = newCost;
                pq.push({newCost,next});
            }
        }

    }

}

int main(){

  int V, E, S;
  cin >> V >> E >> S;
  dist.assign(V + 1, INF); // 정점 번호가 1부터 시작하므로 +1

  for(int i=0; i<E; i++){
    int u,v,w;
    cin>> u >> v>> w;
    graph[u].emplace_back(v,w);
  }
  dijkstra(S);

  for(int i=1; i<=V; i++){
    if(dist[i]==INF)
        cout<<"INF\n";
    else
        cout<<dist[i]<<"\n";
  }

    return 0;
}