#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// 방향성이 없는 드라마

vector<pair<int, int>> graph[8001];

const int INF=1e9;

vector<int> dijstra(int start, int n){
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int,int>,vector<pair<int, int>>, greater<>> pq;
    dist[start] =0;
    pq.push({0,start});

    while(!pq.empty()){
        auto[cur_cost,cur_node] = pq.top();
        pq.pop();

        if(dist[cur_node]<cur_cost) continue;
        
        for(auto[next_node, weight]: graph[cur_node]){
            int next_cost = cur_cost+weight;
            if(next_cost<dist[next_node]){
                dist[next_node] = next_cost;
                pq.push({next_cost,next_node});
            }
        }
    }
    return dist;

}

int main(){

    int N, E;
    cin >>N>>E;

    for(int i=0; i<E; i++){
        int a,b,c;
        cin >> a>>b>>c;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);

    }
    int v1, v2;
    cin >> v1 >>v2;

    vector<int> dist_start = dijstra(1,N);
    vector<int> dist_v1 = dijstra(v1,N);
    vector<int> dist_v2 = dijstra(v2,N);

    int path1 = dist_start[v1] + dist_v1[v2]+dist_v2[N];
    int path2 = dist_start[v2] + dist_v2[v1] + dist_v1[N];

    int result = min(path1,path2);

    if(result >= INF || dist_v1[v2]>=INF) cout<< -1;
    else cout<<result;

    return 0;
}