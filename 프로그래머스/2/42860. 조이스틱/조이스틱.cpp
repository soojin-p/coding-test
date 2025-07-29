#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
a b c d e
f g h i j k l m n 
o p q r s t u
v w x y z


*/
int solution(string name) {
    int answer = 0;
    int n = name.length();
    for(int i=0; i<n; i++){
        if(name[i]<='N'){
            answer+=name[i]-'A';
        }else{
            answer+='Z'-name[i]+1;
        }
    }
    cout<<answer;
    
    int move=n-1;
    for(int i=0;i<n; i++){
        int next = i+1;
        while(next<n && name[next]=='A'){
                next++;
            }
        // B C A B B B
        //왼쪽으로 갔다가 돌아오는 경우
        move = min(move,i+i+n-next);
        // 끝까지 가는 꼉우
        move = min(move,(n-next)*2+i);
    }
    answer+=move;
    return answer;
}