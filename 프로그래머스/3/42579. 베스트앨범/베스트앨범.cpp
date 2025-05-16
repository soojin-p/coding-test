#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// 장르 -> 횟수 -> 고유번호 순으로 정렬

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> g;
    unordered_map<string, vector<pair<int,int>>> p;// 장르 <고유번호, 플레이 수>
    
    for(int i=0; i< genres.size(); i++){
        g[genres[i]]+=plays[i];
        p[genres[i]].push_back({i,plays[i]});
    }
    // 장르별 재생 수 정렬
    vector<pair<string, int>> sorted_g(g.begin(), g.end());
    sort(sorted_g.begin(), sorted_g.end(),[](const auto&a, const auto& b){
        return a.second>b.second;     
    });
    
    // 2곡 선택
    for(auto& genre: sorted_g){
        auto& song = p[genre.first]; // 고유번호, 횟수 
        sort(song.begin(), song.end(),[](const auto&a, const auto&b){
        return a.second== b.second? a.first<b.first : a.second>b.second;      
        });
        for(int i=0; i<song.size() && i<2 ; i++){
        answer.push_back(song[i].first);
    }
    }
    
    return answer;
}