#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> cnt;
    
    for(string name: participant){
        cnt[name]++;
    }
    for(string name: completion){
        cnt[name]--;
    }
    for(auto &p : cnt){
        if(p.second>0) answer = p.first;
    }
    return answer;
}