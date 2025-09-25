#include  <bits/stdc++.h>

using namespace std;

/*
문제 접근 방법:

- 초기 접근
시뮬레이션을 구현해서 cnt로 정렬 횟수를 세기

- 개선 접근:
큰 번호 부터 정렬해야 최소 횟수로 정렬 가능 -> N부터 탐색
뒤에서 부터 탐색하면서 정렬된 책의 개수를 센다
정렬 횟수 = 책의 개수 - 정렬된 책의 개수

시간 복잡도 분석: O(N)

*/
int main()
{
    int N;
    cin >> N;
    vector<int> book(N+1);
    for (int i = 1; i <= N; i++) cin >> book[i]; 
    
    int num=N;
    for(int i=N; i>0;i--){
        if(book[i]==num) num--;
    }
    cout << num;
    return 0;
}
