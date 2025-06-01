#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int max_cnt=0;

void dfs(int k, vector<vector<int>> &dungeons, vector<bool> &visited, int cnt){
    max_cnt = max(cnt, max_cnt);
    
   
    for(int i=0; i<dungeons.size(); i++ ){
        if(k>=dungeons[i][0] && !visited[i]){
            visited[i]=true;
            cout<<i <<" ";
            dfs(k-dungeons[i][1], dungeons,visited,cnt+1);
            visited[i] =false;
           
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int n = dungeons.size();
    vector<bool> visited(n,false);
    dfs(k,dungeons,visited,0);
    
    answer = max_cnt;
    return answer;
}