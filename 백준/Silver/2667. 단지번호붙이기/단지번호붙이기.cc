#include <iostream>
#include <vector>
#include <algorithm>

// 문제
// 출력: 단지수, 각 단지에 속하는 집의 수를 오름차순 정렬
using namespace std;

const int Max =25;
int map[Max][Max];
bool visit[Max][Max];

int N;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dfs(int x, int y){
    visit[x][y] = true;
    int cnt = 1;

    for(int i=0; i<4; i++){
        int nx = x +dx[i];
        int ny = y+dy[i];

        if(nx>=0 && nx<N && ny>=0 && ny<N){
            if(map[nx][ny]==1 &&!visit[nx][ny]){
                cnt+= dfs(nx,ny);
            }
        }
    }
    return cnt;
}

int main (){

   
    cin >> N;
 
    for(int i=0; i<N; i++){
        string st;
        cin >> st;

        for(int j=0; j<N; j++){
           map[i][j]= st[j] -'0';
        }
    }

    vector<int> sizelist;
    for(int i=0; i<N; i++){
        for(int j=0;j<N; j++){
            if(!visit[i][j] && map[i][j]==1){
                int size = dfs(i,j);
                sizelist.push_back(size);
            }
        }
    }  
    sort(sizelist.begin(),sizelist.end());

    cout << sizelist.size()<<endl;
    for(int s : sizelist){
        cout << s <<endl;
    }
}