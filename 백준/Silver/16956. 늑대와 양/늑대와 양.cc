#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vector<string> a(R);
    for (int r = 0; r < R; ++r) cin >> a[r];

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // 1) 늑대 주변에 양이 있는지 먼저 검사
    for (int x = 0; x < R; ++x) {
        for (int y = 0; y < C; ++y) {
            if (a[x][y] != 'W') continue;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (a[nx][ny] == 'S') {
                    cout << 0 << '\n';
                    return 0; // 어떤 식으로 울타리를 둬도 이미 인접: 실패
                }
            }
        }
    }

    // 2) 인접 양이 없는 경우, 늑대 주변 빈칸을 울타리로 채움
    for (int x = 0; x < R; ++x) {
        for (int y = 0; y < C; ++y) {
            if (a[x][y] != 'W') continue;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (a[nx][ny] == '.') a[nx][ny] = 'D';
            }
        }
    }

    // 3) 성공 출력
    cout << 1 << '\n';
    for (int r = 0; r < R; ++r) cout << a[r] << '\n';
    return 0;
}
