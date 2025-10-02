#include <bits/stdc++.h>
using namespace std;

/*

- i번 주사위의 윗면 값 = (i+1)번 주사위의 아랫면 값
- 각 주사위에서 위/아래를 제외한 4면 중 최댓값을 골라 한 옆면의 합을 최대로 만든다.
- 입력 면 순서: A B C D E F, 반대면 쌍은 (A-F), (B-D), (C-E) → 인덱스 (0-5), (1-3), (2-4).

1) 첫 주사위의 윗면 인덱스(0~5)를 모두 시도.
2) 현재 주사위의 윗면 값과 같은 값을 다음 주사위에서 찾아 아랫면으로 두고,
   그 반대면을 윗면으로 set.
3) 주사위마다  4면 중 최댓값을 합산.
4) 6가지 경우 중 최대 합을 출력한다.

*/
int n;
vector<vector<int>> dice;
int OPP[6] = {5, 3, 4, 1, 2, 0};// 반대면 인덱스: (0<->5), (1<->3), (2<->4)

// 위/아래 제외 4면 중 최댓값
int sideMax(int idx, int top) {
    int bot = OPP[top], mx = 0;
    for (int i = 0; i < 6; ++i)
        if (i != top && i != bot) mx = max(mx, dice[idx][i]);
    return mx;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin >> n;
    dice.assign(n, vector<int>(6));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> dice[i][j];

    int answer = 0;

    // 첫 주사위의 윗면 인덱스 6가지 시도
    for (int startTop = 0; startTop < 6; ++startTop) {
        int sum = sideMax(0, startTop);
        int top = startTop; // 현재 주사위의 윗면 인덱스

        // 1 ~ n-1 주사위 연결
        for (int die = 1; die < n; ++die) {
            // (i-1)번째 주사위의 윗면 값과 같은 값을 i번째 주사위에서 찾기 → 그 인덱스가 아랫면
            int botIdx = 0;
            for (int i = 0; i < 6; ++i) {
                if (dice[die][i] == dice[die-1][top]) { botIdx = i; break; }
            }
            top = OPP[botIdx];                 // i번째 주사위의 윗면 인덱스
            sum += sideMax(die, top);
        }
        if (sum > answer) answer = sum;
    }

    cout << answer << '\n';
    return 0;
}
