#include <string>
#include <vector>

using namespace std;
int ans=0;
void func(vector<int> &numbers, int target, int sum, int idx){
    
    if(idx== numbers.size()){
        if(sum==target){
            ans++;
        }
            return;
        }
     func(numbers, target,sum + numbers[idx], idx+1);
    func(numbers, target,sum - numbers[idx], idx+1);
    }
   
    

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
   func(numbers, target, 0,0);
    answer = ans;
    return answer;
}