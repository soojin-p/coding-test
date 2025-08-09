#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int cover = 2 * w + 1; // 기지국 하나가 커버하는 아파트 개수

    int pos = 1; // 현재 커버 시작 위치
    for (int s : stations) {
        int left = s - w;   // 기지국 커버 왼쪽 끝
        if (pos < left) {
            int gap = left - pos; // 커버 안 되는 구간 길이
            answer += (gap + cover - 1) / cover; // 올림 나눗셈
        }
        pos = s + w + 1; // 다음 탐색 시작 지점
    }

    // 마지막 기지국 이후 남은 구간 처리
    if (pos <= n) {
        int gap = n - pos + 1;
        answer += (gap + cover - 1) / cover;
    }

    return answer;
}
