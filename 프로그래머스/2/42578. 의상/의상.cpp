#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// 얼굴, 상의, 하의, 겉옷
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> cnt;
    for(auto cloth : clothes){
        string  name = cloth[0];
        string  type  = cloth[1];
        cnt[type]++;
    }
    
    for(auto it:cnt){
        answer*=(it.second+1);
    }
    return answer-1;
}