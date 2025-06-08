#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

 vector<pair<int, int>> getBlock(vector<vector<int>>& board, int x, int y, int target){
      vector<pair<int, int>> block;
     int n= board.size();
     queue<pair<int, int>> q;
     q.push({x,y});
     block.push_back({x,y});
     board[x][y] =-1;
     
     while(!q.empty()){
         auto [cx, cy] = q.front(); q.pop();
         
         for(int i=0; i<4; i++){
             int nx = cx+dx[i];
             int ny = cy+dy[i];
             
             if(nx>=0 && nx<n && ny>=0 &&ny<n && board[nx][ny]==target){
                 q.push({nx, ny});
                 block.push_back({nx, ny});
                 board[nx][ny] =-1;
             }
         }
     }
     int mx = 1e9, my = 1e9;
     for(auto[px,py]: block){
         mx = min(mx, px);
         my = min(my, py);
     }
     for(auto& [px, py]: block){
         px-=mx;
         py-=my;
     }
    
      sort(block.begin(), block.end());
     // cout<<"target: "<<target<<" "<<block.size()<<endl;
     // for(int i=0; i<block.size(); i++){
     //     cout<<block[i].first<<" "<< block[i].second<<endl;
     // }
     
     //cout<< endl;
     return block;
 }
vector<pair<int, int>> rotate(vector<pair<int, int>> &shape){
     vector<pair<int, int>> rvt;
    
    for(auto& [x,y]: shape){
       rvt.push_back({y,-x});
    }
     int mx = 1e9, my = 1e9;
     for(auto[x,y]: rvt){
         mx = min(mx, x);
         my = min(my, y);
     }
     for(auto& [x, y]: rvt){
         x-=mx;
         y-=my;
     }
     sort(rvt.begin(), rvt.end());
     
     return rvt;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int n = game_board.size();
    vector<vector<pair<int, int>>> blank;
    vector<vector<pair<int, int>>>  puzzle;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(game_board[i][j]==0){
                blank.push_back(getBlock(game_board, i,j,0));
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(table[i][j]==1){
                puzzle.push_back(getBlock(table, i,j,1));
            }
        }
    }
    vector<bool> used(puzzle.size(),false);
    for(auto b: blank){
        bool match = false;
        for(int i=0; i<puzzle.size(); i++){
        auto shape = puzzle[i];
        
        if(used[i] || b.size()!=shape.size()) continue;
            
            for(int r=0; r<4; r++){
                cout<<b.size()<<" "<< r<<endl;
                if(b==shape){
                    
                    answer+=shape.size();
                    used[i] =true;
                    match = true;
                    break;
                }
                shape = rotate(shape);
            }
            if(match) break;
        }
    }
    
    return answer;
}