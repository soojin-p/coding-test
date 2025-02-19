#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int maxSafeZone = 0;
vector<pair<int, int>> directions = {{0,-1}, {0,1}, {-1,0}, {1,0}}; // 상하좌우 이동

// 바이러스 확산 (BFS)
int spreadVirus(vector<vector<int>> grid) {
    queue<pair<int, int>> q;

    // 초기 바이러스 위치를 큐에 삽입
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) q.push({i, j});
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                grid[nx][ny] = 2;  // 바이러스 확산
                q.push({nx, ny});
            }
        }
    }

    // 안전 영역(0의 개수) 계산
    int safeZone = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                safeZone++;
            }
        }
    }
    return safeZone;
}

// 벽 세우기 (백트래킹 - DFS)
void buildWall(vector<vector<int>>& grid, int cnt) {
    if (cnt == 3) {  // 벽을 3개 세우면 바이러스 확산 후 안전 영역 계산
        maxSafeZone = max(maxSafeZone, spreadVirus(grid));
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {  // 빈 공간에만 벽 세우기 가능
                grid[i][j] = 1;  // 벽 세우기
                buildWall(grid, cnt + 1);
                grid[i][j] = 0;  // 원상복구 (백트래킹)
            }
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    buildWall(grid, 0);  // 벽 세우기 시작
    cout << maxSafeZone << endl;  // 최댓값 출력
    return 0;
}
