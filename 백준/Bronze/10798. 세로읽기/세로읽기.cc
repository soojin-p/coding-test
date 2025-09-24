#include <bits/stdc++.h>
using namespace std;

/*
[접근 방법]
- 5줄 문자열을 통째로 입력받고,
- 열 인덱스 j = 0..14, 행 i = 0..4 순서로 순회하면서
  j가 해당 행 문자열 길이보다 작을 때만 st[i][j] 출력.

[시간 복잡도]
- 최대 5 * 15 칸만 검사 -> O(1) (상수).
  일반화하면 전체 문자 수 M에 대해 O(M).

[공간 복잡도]
- 입력 저장용 5개의 문자열 -> O(M) (M은 입력 전체 길이).
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> st(5);
    for (int i = 0; i < 5; ++i) {
        getline(cin, st[i]);       
    }

    for (int j = 0; j < 15; ++j) {  
        for (int i = 0; i < 5; ++i) {
            if (j < (int)st[i].size())  // 범위 내일 때만 출력
                cout << st[i][j];
        }
    }
    return 0;
}
