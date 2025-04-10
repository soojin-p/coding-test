#include<iostream>
#include <vector>


using namespace std;

const int MAX=100001;
vector<int> graph[MAX];
bool visited[MAX];
int parents[MAX];

int N;
void dfs(int node){
    visited[node]=true;

    for(int next: graph[node]){
        if(!visited[next]){
            parents[next]=node;
            dfs(next);
        }
    }

}
int main(){
    cin>>N;
    for(int i=0; i<N-1; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    
    dfs(1);

    for(int i=2;i<=N; i++){
        cout<<parents[i]<<"\n";
    }
    return 0;
}