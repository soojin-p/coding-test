#include<iostream>
#include <vector>


using namespace std;


int N,M;
bool visited[9];
int arr[9];
void funcprint(){
    for(int i=0; i<M; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void dfs(int depth){
 
    if(depth==M){
        // 출력
        funcprint();
        return; 
    }
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[depth]=i;
            dfs(depth+1);
            visited[i]=false;
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
   
   dfs(0);
    return 0;
}