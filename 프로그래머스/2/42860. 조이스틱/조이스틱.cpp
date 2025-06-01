#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// a b c d e f g h i j k l m
// n o p q r s t u v w x y z
// 21-9 = 12

int solution(string name) {
    int answer = 0;
    int len = name.length();
    for(char c: name){
        answer+= min(c-'A', 'Z'-c+1);
    }
    int move = len-1;
    for(int i=0; i<len; i++){
        int next = i+1;
        // len- next : next인덱스 부터 끝까지 처리해야하는 문자 수
        while (next<len && name[next]=='A') next++;
        move = min(move, i + len - next + min(i, len-next));
    }
    answer +=move;
    return answer;
}