#include <iostream>
#include <sstream>
using namespace std;

int N, M;
bool visited[9];
int arr[9];
ostringstream result;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            result << arr[i] << ' ';
        }
        result << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i;
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    dfs(0);

    cout << result.str();  // 한 번에 출력
    return 0;
}
