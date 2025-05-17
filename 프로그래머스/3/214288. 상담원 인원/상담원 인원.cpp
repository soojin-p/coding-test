#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int simulate(int k, const vector<vector<int>> &reqs, const vector<int> &assign){
    vector<priority_queue<int, vector<int>, greater<int>>> mentors(k);
    
    int total_wait =0;
    
    for(int i=0; i<k; i++){
        for(int j=0; j<assign[i]; j++){
            mentors[i].push(0);
        }
    }
    
    for(const auto&r:reqs){
        int start = r[0];
        int dur = r[1];
        int type = r[2]-1;
        
        auto&pq = mentors[type]; // 해당 유형의 멘토 큐
        int avail = pq.top(); pq.pop();
        
        if(avail <= start){
            pq.push(start+dur); // 바로 상담 종료 시간 갱신
        }
        else{
            total_wait +=(avail -start); // 대기 추가
            pq.push(avail+dur);//  상담종료 시간 갱신
        }
        
    }
    return total_wait;
}
// 멘토 배분 조합 dfs
void dfs(int dep, int remain, vector<int>&assign, int k, const vector<vector<int>> &reqs, int & min_wait){
    if(dep==k){
        if(remain ==0){
            int wait = simulate(k,reqs,assign);
            min_wait = min(min_wait, wait);
        }
        return;
    }
    for(int i=1; i<=remain; i++){
        assign[dep]=i;
        dfs(dep+1,remain-i,assign, k, reqs, min_wait);
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    
    int min_wait = INT_MAX;
    vector<int> assign(k,1);
    dfs(0,n,assign,k,reqs,min_wait);
    
    answer = min_wait;
    return answer;
}