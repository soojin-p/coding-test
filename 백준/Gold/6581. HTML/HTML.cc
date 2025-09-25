#include <bits/stdc++.h>

using namespace std;

/*
문제 접근 방법:

입력값의 길이를 모를 때 입력 받는 방법
char a;

while(cin >> a){ //while(!(cin >> a).eof)
    cout << a;
}
- 스트림 연산 뒤에는 스트림 객체 반환
- 그러나 스트림이 조건문에 들어가면 bool로 변환되어 true/false 반환
참고: https://velog.io/@c-jeongyyun/CPP-EOF-%ED%8C%90%EB%8B%A8%ED%95%98%EA%B8%B0

시간 복잡도 분석: O(L) (L = 전체 입력 길이).

*/
#define NLINE  cout << "\n"; len = 0;
int main()
{
    string st;
    int len = 0;
    while (cin >> st){
        if (st == "<br>"){NLINE;}
        else if (st == "<hr>"){
            if (len != 0) NLINE;
            for(int i=0; i<80; i++) cout << "-";
            NLINE;
        }
        else{
            if (lineLen + st.length() >= 80) {NLINE;}
            else{
                if (len != 0){
                    cout << " ";
                    len++;
                }
            }
            cout << st;
            len += st.length();
        }
    }
    return 0;
}

