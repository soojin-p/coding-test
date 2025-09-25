#include  <bits/stdc++.h>

using namespace std;


/*
문제 접근 방법:
1. 차량 입차 시 대기 큐에 차량 번호를 추가
2. 차량 출차 시 해당 차량의 주차 요금을 계산하고, 주차장을 비움
3. 대기 큐에서 차량을 꺼내 빈 주차장에 주차
4. 주차 공간 우선순위는 for문으로 구현 


시간 복잡도 분석:
주차 칸 선형 탐색 O(N)
차량 입출차 2M번 O(2M)
전체 시간 복잡도 O(N*2M) = O(NM)

*/

int N,M; // N: 주차장 수, M: 차량 수
// 주차료 = 차량의 무게 * 주차장 요금
int main(){
    cin >> N >> M;

    vector<int> fee(N+1);
    vector<int> weight(M+1);
    vector<int> parkingLot(N+1,-1); // 주차장 상태 -1: 빈자리, 양수: 차량번호
    queue<int> waitingCar; // 대기 차량

    int totalFee=0;

    for(int i=1; i<=N; i++) cin >> fee[i];
    for(int i=1; i<=M; i++) cin >> weight[i];
    for(int i=0; i<M*2; i++){
        int car;
        cin >> car;
        if(car>0) waitingCar.push(car); // 입차
        else{                   // 출차 
            car = -car;
            for(int j=1; j<=N; j++){
                 if(parkingLot[j]==car){
                    totalFee += weight[car] * fee[j];
                    parkingLot[j]=-1;
                    break;
                }
            }
        }
        if(!waitingCar.empty()){// 대기 차량이 있으면 주차
            for(int j=1; j<=N; j++){
                if(parkingLot[j]==-1){
                    parkingLot[j]=waitingCar.front();
                    waitingCar.pop();
                    //totalFee += weight[parkingLot[j]] * fee[j];
                    break;
                }
            }
        }
    }
    cout << totalFee;
    return 0;
}
