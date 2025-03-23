#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 문제:흰지렁이가 해충을 잡아먹음 -> 몇개 흰지렁이가 필요한가-> 섬 개수 세는 문제
// 출력: 테스트케이스 - 지렁이 개수

int T;
int M,N,K;

vector<vector<int>> map;
vector<vector<bool>> visit;
int dx[4] = {0,0,-1,1};
int dy[4] ={ -1,1,0,0};

void dfs(int x, int y){
    visit[y][x] = true;
   
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && nx<M && ny>=0 &&ny<N){
            if(map[ny][nx]==1 && !visit[ny][nx]){
                dfs(nx,ny);
            }
        }
    }
}
int main(){

    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> M >> N >> K;

        map.clear();
        visit.clear();

        map.resize(N, vector<int>(M,0));
        visit.resize(N, vector<bool>(M,false));

        for(int k=0; k<K; k++){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        int cnt=0;
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                if(map[y][x]==1 && !visit[y][x]){
                   
                    dfs(x, y);
                    cnt++;
                }
            }
        }

        cout<< cnt <<endl;
    }

    
    return 0;
}


