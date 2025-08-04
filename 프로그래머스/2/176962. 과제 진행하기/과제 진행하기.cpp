#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int timeToint(string t){
    return stoi(t.substr(0,2))*60 + stoi(t.substr(3));
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(),plans.end(),[](auto&a, auto &b){
        return timeToint(a[1])< timeToint(b[1]);
    });
    
    int now = timeToint(plans[0][1]);
    stack<pair<string, int>> paused;
    
    for(int i=0; i<plans.size(); i++){
        string name = plans[i][0];
        int start = timeToint(plans[i][1]);
        int duration = stoi(plans[i][2]);
        
        while(!paused.empty() && now< start){
            auto&[pName, remain] =  paused.top();
            int availTime = start-now;
            if(remain<= availTime){
                answer.push_back(pName);
                 now+=remain;
                 paused.pop();
            }else{
                now=start;
               
                remain-=availTime;
            }
        }
        now =start;
        if(i+1<plans.size()){
            paused.push({name,duration});
        }
        else{
            answer.push_back(name);
            now+=duration;
        }
    }
    
    while(!paused.empty()){
        answer.push_back(paused.top().first);
        paused.pop();
    }
    return answer;
}