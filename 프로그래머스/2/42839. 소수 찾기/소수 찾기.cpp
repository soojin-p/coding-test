#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
bool isPrime(int num){
    if(num==1 || num==0) return false;
    for(int i=2; i< num; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}   

int solution(string numbers) {
    int answer = 0;
    int n = numbers.size();
    
    set<int> comb;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int len =1; len <=numbers.size(); len++){
            int num=0;
            for(int i=0; i<len; i++){
                num= num*10 +(numbers[i]-'0');
            }
            comb.insert(num);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
   vector<int> nums(comb.begin(), comb.end());
    for(int i=0; i<nums.size(); i++){
        if(isPrime(nums[i])) {
            cout<<nums[i]<< ' ';
            answer++;
        }
    }
    return answer;
}