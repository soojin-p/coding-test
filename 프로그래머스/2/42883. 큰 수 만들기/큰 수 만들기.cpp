#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.length();
    stack<char> st;
    int cnt=0;
    for(int i=0; i<n; i++){
        char cur = number[i];
        
        while(!answer.empty() && answer.back()<cur && cnt<k){
            answer.pop_back();
            cnt++;
        }
        answer.push_back(cur);
    }
     while(cnt < k) {
        answer.pop_back();
        cnt++;
    }
    
    
    return answer;
}