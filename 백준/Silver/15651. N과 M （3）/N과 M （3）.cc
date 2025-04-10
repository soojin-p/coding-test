#include<iostream>
#include <vector>


using namespace std;

int N,M;
bool visited[8];
int list[8];

void dfs(int dep,int s){
    if(dep==M){
        for(int i=0; i<M; i++){
            cout<<list[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=s; i<=N; i++){
        list[dep]=i;
        dfs(dep+1,s);
        
    }

}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin>>N>>M;

    dfs(0,1);
   return 0;
}