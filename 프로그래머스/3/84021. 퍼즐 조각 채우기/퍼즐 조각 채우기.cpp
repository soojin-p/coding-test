#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<pair<int, int>> getBlock(vector<vector<int>> &board, int x, int y, int target){
    int n = board.size();
    
    vector<pair<int, int>> block;
    board[x][y] =-1;
    queue<pair<int, int>> q;
    q.push({x,y});
    block.push_back({x,y});

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cx +dx[i];
            int ny = cy +dy[i];
            
            if(nx>=0 &&nx<n && ny>=0 && ny<n && board[nx][ny]== target){
                board[nx][ny]=-1;
                q.push({nx,ny});
                block.push_back({nx, ny});
            }
        }
    }
     int minx = 1e9, miny = 1e9;
    for(auto [px, py] : block){
        minx = min(minx, px);
        miny = min(miny, py);
    }
    for(auto &p : block){
        p.first -= minx;
        p.second -= miny;
    }
    sort(block.begin(), block.end());
    return block;
}
vector<pair<int, int>> rotate(vector<pair<int, int>> shape){
    vector<pair<int, int>> rvt;
    
    for(auto [x,y] : shape){
        rvt.push_back({y,-x});
    }
    int minx =1e9, miny=1e9;
    
    for(auto [x,y] : rvt){
        minx = min(minx,x);
        miny = min(miny,y);
    }
    for(auto& [x,y] : rvt){
        x-=minx;
        y-=miny;
    }
    sort(rvt.begin(), rvt.end());
     
    return rvt;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer=0;
    int n = game_board.size();
    vector<vector<pair<int, int>>> blank;
    vector<vector<pair<int, int>>> puzzle;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(game_board[i][j]==0){
                blank.push_back(getBlock(game_board,i,j,0));
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(table[i][j]==1){
                puzzle.push_back(getBlock(table,i,j,1));
            }
        }
    }

    vector<bool> used(puzzle.size(), false);
    for(auto &b: blank){
        bool match=false;
        
        for(int i=0; i< puzzle.size(); i++){
            if(used[i] || b.size() != puzzle[i].size()) continue;
            
            //출력
            cout<<"빈칸: "<<b.size();
             for(auto [x,y]: b){
                cout << "(" << x << "," << y << ") ";
            }
            cout << endl;
            auto shape = puzzle[i];
              
            for(int r =0; r<4; r++){  
                 cout<<"퍼즐: "<<shape.size();
             for(auto [x,y]:shape){
                cout << "(" << x << "," << y << ") ";
            }
            cout << endl;
                 //cout<< shape.size()<< " "<<b.size()<< " "<<r<<endl;
                if(b == shape){
                 
                    used[i] =true;
                    match =true;
                   
                    answer+= shape.size();
                    break;
                }
                cout<< shape.size()<<" ";
                shape = rotate(shape);
            }
            if(match) break;
        }
    }
    
    return answer;
}