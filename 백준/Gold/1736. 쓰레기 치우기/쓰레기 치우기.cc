#include <stdio.h>

int n, m;
int board[105][105];  

int solve(int y, int x, int c) {
    int flag = 0;
    for (int j = y; j < n; ++j) {
        for (int i = x; i < m; ++i) {
            if (board[j][i] == 1) {
                board[j][i] = 0;
                c = c + 1 + solve(j, i, c);  // 재귀로 지울 수 있는 것 지움
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    return c;
}

int main(void) {
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &board[i][j]);
        }
    }

    int v = 1;
    for (int i = 0; i < n + 2; ++i) {
        if (v == 0) {
            printf("%d\n", i - 1);
            break;
        }
        v = solve(i, 0, 0);
    }
    return 0;
}
