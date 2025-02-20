#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    cout << node << " ";
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    vector<bool> visited_bfs(N + 1, false); // BFS 방문 여부 배열

    q.push(start);
    visited_bfs[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : graph[cur]) {
            if (!visited_bfs[next]) {
                q.push(next);
                visited_bfs[next] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;
    graph.resize(N + 1);

    // 그래프 입력
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 양방향 그래프
    }

    // 각 정점의 연결 리스트를 정렬 (작은 번호부터 방문하도록)
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 실행
    visited.assign(N + 1, false); // 방문 배열 초기화
    dfs(V);
    cout << endl;

    // BFS 실행
    bfs(V);
    cout << endl;

    return 0;
}
