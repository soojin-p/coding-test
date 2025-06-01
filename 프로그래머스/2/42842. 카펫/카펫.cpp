#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// 브브브브브
// 브노노노브
// 브브브브브


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    
    int h=3; // 세로
    int w = total/h;
    
    while(w>=h){
        w = total/h;
        if((w-2)*(h-2)==yellow){
            answer.push_back(w);
           answer.push_back(h);
           break;
        }
        h++;
    }
    
    return answer;
}