#include  <bits/stdc++.h>


using namespace std;

int N,M; // N: 주차장 수, M: 차량 수
// 주차료 = 차량의 무게 * 주차장 요금
int main(){
    cin >> N >> M;

    vector<int> fee(N+1);
    vector<int> weight(M+1);
    vector<int> parkingLot(N+1,-1); // 주차장 상태 -1: 빈자리, 양수: 차량번호
    queue<int> waitingCar; // 대기 차량

    int toalFee=0;

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
                    toalFee += weight[parkingLot[j]] * fee[j];
                    break;
                }
            }
        }
    }
    //cout<<"\n";
    cout << toalFee;
    return 0;
}