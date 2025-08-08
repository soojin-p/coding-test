#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize==0) return cities.size()*5;
    int answer = 0;
    vector<string> cache;
    for(string city: cities){
        for(auto &ch:city) ch = tolower(ch);
        auto it = find(cache.begin(), cache.end(),city);
        
        if(it !=cache.end()){ // 캐시안에 있다면
            answer+=1;
            cache.erase(it);
            cache.insert(cache.begin(),city);
        }
        else{
            answer+=5;
            if(cache.size()==cacheSize){// 캐시가 찼으면
                cache.pop_back();
            }
            cache.insert(cache.begin(),city);
        }
    }
    return answer;
}