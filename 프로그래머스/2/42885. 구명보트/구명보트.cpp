#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    sort(people.begin(), people.end());
    
    for(int p: people){
        dq.push_back(p);
    }
    // 50 50 70 80
    // 50 70 80
    while(!dq.empty()){
        if(dq.size()==1){
             answer++;
            break;
        }
        if(dq.front()+dq.back()>limit){
            answer++;
            dq.pop_back();
        }
        else{
            answer++;
            dq.pop_front();
            dq.pop_back();
        }
    }
    return answer;
}