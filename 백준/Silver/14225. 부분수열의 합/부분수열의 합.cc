#include <bits/stdc++.h>

using namespace std;
/*

풀이
- 백트래킹으로 모든 부분합을 탐색하며 가능한 합을 기록
- 0부터 총합까지 중 방문되지 않은 첫 번째 자연수가 정답
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

