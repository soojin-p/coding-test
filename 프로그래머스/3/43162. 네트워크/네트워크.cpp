#include <string>
#include <vector>

using namespace std;
void dfs(vector<vector<int>>& computers, vector<bool> &visited, int node){
    visited[node] =true;
    for(int i=0; i<computers.size(); i++){
        // 자기 자신이 아니고, 연결되어 있고, 방문하지 않은 경우
        if(i!=node && computers[node][i]==1 &&!visited[i])
            dfs(computers,visited,i);
        }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,0);
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(computers, visited, i);
            answer++;
        }
    }
    return answer;
}