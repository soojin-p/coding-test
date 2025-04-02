#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
int N, E;
vector<pair<int, int>> graph[8001]; // 인접 리스트

vector<int> dijkstra(int start) {
    // 1. 모든 노드의 거리를 무한대로 초기화
    vector<int> dist(N + 1, INF);

    // 2. 최소 힙(우선순위 큐) 선언: (비용, 노드번호)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    // 3. 시작 노드까지의 거리는 0으로 설정
    dist[start] = 0;

    // 4. 시작 노드를 큐에 삽입
    pq.push({0, start});

    // 5. 큐가 빌 때까지 반복
    while (!pq.empty()) {
        // 6. 가장 짧은 거리를 가진 노드 꺼내기
        auto [cost, now] = pq.top();
        pq.pop();

        // 7. 이미 더 짧은 경로로 방문한 적 있다면 스킵
        if (dist[now] < cost) continue;

        // 8. 현재 노드에 연결된 모든 인접 노드 순회
        for (auto [next, w] : graph[now]) {
            // 9. 현재 노드를 거쳐서 next로 가는 비용 계산
            int next_cost = dist[now] + w;

            // 10. 더 짧은 경로를 찾으면 갱신
            if (next_cost < dist[next]) {
                dist[next] = next_cost;
                pq.push({next_cost, next}); // 큐에 새 경로 추가
            }
        }
    }

    // 11. 최단 거리 결과 반환
    return dist;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c); // 무방향 그래프
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist_start = dijkstra(1);
    vector<int> dist_v1 = dijkstra(v1);
    vector<int> dist_v2 = dijkstra(v2);

    int path1 = dist_start[v1] + dist_v1[v2] + dist_v2[N];
    int path2 = dist_start[v2] + dist_v2[v1] + dist_v1[N];
    int result = min(path1, path2);

    // 경로가 불가능한 경우 체크
    if (dist_start[v1] >= INF || dist_v1[v2] >= INF || dist_v2[N] >= INF ||
        dist_start[v2] >= INF || dist_v2[v1] >= INF || dist_v1[N] >= INF) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}