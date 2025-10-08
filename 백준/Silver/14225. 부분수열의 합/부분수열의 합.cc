#include <bits/stdc++.h>

using namespace std;
/*
문제이해

풀이

*/

vector<int> nums;
vector<bool> visited;
int N;
int totalSum;

void backtrack(int i, int sum){
    visited[sum] = true; // 방문처리
    if(i==N ) return;
    
    backtrack(i+1, sum); // i번째 수를 선택하지 않는 경우
    backtrack(i+1, sum+nums[i]); // i번째 수를 선택하는 경우
}

int main() {
    cin>>N;
    nums.resize(N);
    for(int i=0; i<N; i++) {
        cin>>nums[i];
        totalSum += nums[i];
    }
    visited.resize(totalSum+1, false);
    sort(nums.begin(), nums.end());

    backtrack(0, 0);

    int ans = 0;
    while(visited[ans]) ans++;
    cout<<ans;
    return 0;
}
