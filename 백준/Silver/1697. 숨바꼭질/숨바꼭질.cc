#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 문제:흰지렁이가 해충을 잡아먹음 -> 몇개 흰지렁이가 필요한가-> 섬 개수 세는 문제
// 출력: 테스트케이스 - 지렁이 개수
const int MAX = 100001;
int visit[MAX];

int N, K;

int bfs(int N,int K){
    queue<int> q;
    q.push(N);
    visit[N] =1;

    while (!q.empty())
    {
        int now =q.front();
        q.pop();

        if(now==K){
            return visit[now]-1;
        }
        for(int next: {now-1, now+1, now*2}){
            if(next>=0 && next <MAX && visit[next]==0){
                visit[next] = visit[now]+1;
                q.push(next);
            }
        }
    }
    return -1;

}
int main(){
    cin >> N >>K;
    cout << bfs(N, K) << endl;

    return 0;
}
