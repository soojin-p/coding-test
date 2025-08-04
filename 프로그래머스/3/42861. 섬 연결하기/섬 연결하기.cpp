#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//부모 노드 찾기
int findParents(vector<int> &parents, int n){
    if(parents[n]!=n){
        parents[n] = findParents(parents,parents[n]);
    }
    return parents[n];
}
// 부모 노드 연결
void unit(vector<int> &parents, int a, int b){
     a = findParents(parents,a);
     b = findParents(parents,b);
    if(a<b) parents[b] = parents[a];
    else parents[a] = parents[b];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parents(n);
    sort(costs.begin(), costs.end(), [](auto&a, auto&b){
        return a[2]<b[2];
    });
   for(int i=0; i<n; i++) parents[i]=i;
    int edgeCnt=0;
    
    for(auto& node: costs){
        int u = node[0], v=node[1],cost = node[2];
        if(findParents(parents,u) !=findParents(parents,v)){
            unit(parents,u,v);
            answer+=cost;
            edgeCnt++;
        }
        if(edgeCnt==n-1){
            break;
        }
        
    }
    return answer;
}