#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*

문제 이해:
N극은 0, S극은 1
맞닿은 극이 
    -다르면, 반대방향으로 회전
    - 같다면, 회전X

입력은 12시 방향부터 입력
좌idx: 6, 우idx 2

접근 방법
1. 회전 톱니바퀴 번호, 회전방향 입력받음
2. 톱니바퀴 기준 좌/우로 방향 변경
3. 회전

시간복잡도:명령 K개에 대해 매번 최대 4개 비교 + 4개 회전 → O(K).
*/
int main() {
    vector<vector<int>> wheel(4, vector<int>(8));
    for(int i=0; i<4; i++){
        string st;
        cin>>st;
        for(int j=0; j<8; j++){
            wheel[i][j]=st[j]-'0';
        }
    }
    //
    int K; cin>>K;
    for(int k=0; k<K; k++){
        int num, dir; //num: 톱니바퀴의 번호, dir: 1:시계방향, -1 반시계방향
        cin>>num>> dir; num--;
        vector<int>rotateDir(4,0);
        rotateDir[num] = dir;

        //num 왼쪽 톱니바퀴 
        for(int i=num-1; i>=0; i--){
            if(wheel[i][2]!=wheel[i+1][6]){
                rotateDir[i]=-rotateDir[i+1];
            }
            else break;
        }
        // num 오른쪽 톱니바퀴
        for(int i=num+1; i<4; i++){
             if(wheel[i][6]!=wheel[i-1][2]){
            rotateDir[i]=-rotateDir[i-1];
            }
          else break;
        }
        
        //회전
        for(int i=0; i<4; i++){
            if(rotateDir[i]==1){ //시계방향
                int tmp = wheel[i][7];
                for(int j=7; j>0; j--){
                    wheel[i][j] = wheel[i][j-1];
                }
                wheel[i][0]=tmp;
            }
            else if(rotateDir[i]==-1){ //시계반대방향
                int tmp = wheel[i][0];
                for(int j=0; j<8-1; j++){
                    wheel[i][j]=wheel[i][j+1];
                }
                wheel[i][7] = tmp;
            }
        }
    }
   
    // 점수 계산
    int score=0;
    int base=1;
    for(int i=0; i<4; i++){
        if(wheel[i][0]==1) score+=base;
        base*=2;
    }
    cout<<score;
    
    return 0;
}