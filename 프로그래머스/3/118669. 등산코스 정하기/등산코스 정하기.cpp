#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<vector<pair<int, int>>> graph(n+1);
    vector<bool> isGate(n+1);
    vector<bool> isSummit(n+1);
    
    for(auto g:gates)isGate[g]=true;
    for(auto s:summits)isSummit[s]=true;
    
    for(auto path: paths){
        int a=path[0], b=path[1],w=path[2];
        // a->b
        if(isGate[a] || isSummit[b]) {
            graph[a].push_back({b,w});
        }
        //b->a
        else if(isGate[b] || isSummit[a]) {
            graph[b].push_back({a,w});
        }
        else {
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    vector<int> intensity(n+1, 1e9);
    for(auto g: gates) {
        intensity[g]=0;
        pq.emplace(0, g);
    }
    while(!pq.empty()){
        auto [curIntense, curNode] = pq.top();
        pq.pop();
        
        if(intensity[curNode]<curIntense)continue;
       
        for(auto&[ nextNode, cost]:graph[curNode]){
            int nextIntense = max(cost,curIntense);
            if(nextIntense<intensity[nextNode]){
                intensity[nextNode]=nextIntense;
                pq.emplace(nextIntense,nextNode );
            }
        }
    }
    sort(summits.begin(), summits.end());
    int minIntese =1e9,minNode =0;
    for(auto s: summits){
        if(intensity[s]< minIntese){
            minNode =s;
            minIntese=intensity[s];
        }
    }
    answer.push_back(minNode);
    answer.push_back(minIntese);
    return answer;
}