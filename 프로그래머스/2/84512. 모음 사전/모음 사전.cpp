#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// a e i o u -> 5개
//aa ae ai ao au -> 25개
//ea ee ei eo eu

// 5^n
int solution(string word) {
    int answer = 0;
    vector<char> vt = {'A','E','I','O','U'};
    
    //1 5 25 125 625
    vector<int> weight(5,0);
    int base=1;
    for(int i=4; i>=0; i--){
        weight[i] = base;
        base = base*5+1;
    }
    
    for(int i=0; i< word.size(); i++){
        int idx = find(vt.begin(), vt.end(), word[i])-vt.begin();
        
        answer += idx*weight[i]+1;
        cout<< answer<<" ";
    }
    
       
    return answer;
}