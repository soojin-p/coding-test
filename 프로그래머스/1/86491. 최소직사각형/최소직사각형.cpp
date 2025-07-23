#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> orderd_r();
    vector<int> orderd_c();
    sort(sizes.begin(), sizes.end());
    for(int i=0; i< sizes.size(); i++){
        if(sizes[i][0]<sizes[i][1]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    int max_r=0;
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][0]>max_r){
            max_r = sizes[i][0];
        }
    }
    int max_c=0;
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][1]>max_c){
            max_c = sizes[i][1];
        }
    }
    answer = max_r*max_c;
   
    return answer;
}