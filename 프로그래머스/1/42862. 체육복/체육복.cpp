#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// 1 2 3 4 5
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<int> real_lost;
    vector<int> real_reserve;
    
    for(int l: lost){
        auto it = find(reserve.begin(), reserve.end(),l);
        if(it != reserve.end()){
             reserve.erase(it);
        }
        else{
            real_lost.push_back(l);
        }
    }
    real_reserve = reserve;
    answer = n- real_lost.size();
    
    for(int l: real_lost){
        auto it1 = find(real_reserve.begin(), real_reserve.end(),l-1);
        if(it1 !=real_reserve.end()){
            answer++;
            real_reserve.erase(it1);
            continue;
        }
        auto it2 = find(real_reserve.begin(), real_reserve.end(),l+1);
        if(it2 !=real_reserve.end()){
            answer++;
            real_reserve.erase(it2);
            continue;
        }
        
    }
    return answer;
}