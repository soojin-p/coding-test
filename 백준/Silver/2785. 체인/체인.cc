#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<int> num(N);
    for (int i = 0; i < N; ++i) cin >> num[i];
    sort(num.begin(), num.end());

    int ans = 0;
    int needded = N; // 남은 체인 개수

    for (int i = 0; i < N; ++i) {
        if (needded > 1) {
            int can = needded - 1;   // 이번에 최대 붙일 수 있는 개수 상한
            int use;
            if (num[i] < can) use = num[i];
            else use = can;

            ans += use;
            needded -= (use + 1);
        } else {
            break;
        }
    }

    cout << ans;
    return 0;
}
