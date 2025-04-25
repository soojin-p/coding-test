#include <bits/stdc++.h>
using namespace std;

int ans =0;
void dfs(vector<int> &numbers, int target, int idx, int sum){
   if(idx == numbers.size()){
       if(sum==target) {
           ans++ ;}
        return;
   }
    dfs(numbers, target,idx+1,sum+numbers[idx]);// 현재숫자
    dfs(numbers, target,idx+1,sum-numbers[idx]);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers,target,0,0);
    answer = ans;
    return answer;
}