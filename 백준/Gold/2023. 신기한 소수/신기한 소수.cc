#include <bits/stdc++.h>

using namespace std;

/*

문제 접근 방법:
dfs로 구현
- 1~9까지의 숫자 중에서 소수인 것부터 시작
- 자릿수를 하나씩 늘려가면서 소수인지 확인
- 자릿수가 N이 되면 출력

시간 복잡도 분석:   

*/

void dfs(int num, int dep, int N){// num: 현재 숫자, dep: 현재 자릿수
    if(dep  ==N){
        cout << num << "\n";
        return;
    }
    for(int i=0; i<10; i++){
        int newNum = num*10 + i;//
        bool isPrime = true;
        for(int j=2; j*j<=newNum; j++){
            if(newNum%j==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime) dfs(newNum, dep+1, N);
    }
}
int main()
{
    int N;
    cin >> N;
    dfs(2,1,N);
    dfs(3,1,N);
    dfs(5,1,N);
    dfs(7,1,N);

    return 0;
}