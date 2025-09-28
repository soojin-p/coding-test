#include <bits/stdc++.h>

using namespace std;
/*
문제이해
    N×M 크기의 공간
    한 칸에는 아기 상어가 최대 1마리
    0은 빈 칸, 1은 아기 상어가 있는 칸
    안전거리: 어떤 빈 칸에서 가장 가까운 아기 상어까지의 거리
    거리: 지나는 칸의 개수 

    ex) 0 0 1 0 0
        0 0 0 0 0
        0 1 0 0 0
        0 0 0 0 1
        0 0 0 0 0
    (0,0)에서 (0,2)까지의 거리는 2

==>  최단거리 중에서 가장 큰 값 구하는 문제

접근 방법: BFS로 최단거리 구하기
1. 상어의 위치를 큐에 넣고, 거리를 0으로 설정
2. 큐에서 하나씩 꺼내서 이동하면서 거리를 갱신
*/
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> space(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M, -1)); // 거리 저장
    queue<pair<int, int>> q; // 상어 위치 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> space[i][j];
            if(space[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    int max_dist = 0;

    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};// 우 좌 상하 대각선
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            max_dist = max(max_dist, dist[nx][ny]);
            q.push({nx, ny});
        }
    }
    cout << max_dist;
    return 0;
}
