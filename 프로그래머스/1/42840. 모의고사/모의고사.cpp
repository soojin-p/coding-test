#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> supoja1 ={1,2,3,4,5};
vector<int> supoja2 ={2,1,2,3,2,4,2,5,};
vector<int> supoja3 ={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    int n = answers.size();
    vector<int> answer;
      vector<pair<int,int>>p;
    for(int i=0; i<3; i++){
        p.push_back({i+1,0});
    }
    for(int i=0; i<n; i++){
        if(answers[i]==supoja1[i%5])p[0].second++;
        if(answers[i]==supoja2[i%8])p[1].second++;
        if(answers[i]==supoja3[i%10])p[2].second++;
    }
  int  max_score = max({p[0].second,p[1].second,p[2].second});
    for(int i=0; i<3; i++){
       if(p[i].second==max_score)answer.push_back(p[i].first);
    }
    return answer;
}