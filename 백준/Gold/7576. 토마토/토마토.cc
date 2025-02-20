#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector<vector<int>> grid;
queue<pair<int, int>> q;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs()
{
    int days = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dir)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 0)
            {
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
                days = max(days, grid[nx][ny]);
            }
        }
        /* code */
    }

    return days-1;
}
int main()
{
    int ans;
    cin >> M >>N;
    grid.assign(N, vector<int>(M));
    bool isall = true;
    // grid.resize(N+1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                q.push({i, j});
            }
            if (grid[i][j] == 0)
            {
                isall = false;
            }
        }
    }
    if (isall)
    {
        cout << 0;
        return 0;
    }
    ans = bfs();
    // 익지 않은 토마토가 남아있는지 확인
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 0){
                cout<< -1;
                return 0; // 익지 않은 토마토가 남아있다면 -1 반환
            }
               
        }
    }
    cout << ans;
    return 0;
}
