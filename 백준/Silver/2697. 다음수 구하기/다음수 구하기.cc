#include <stdio.h>
#include <bits/stdc++.h>


/*
문제이해:
    구성으로 만들 수 있는 수 중에서, 현재값보다 큰수
접근방법:
    현재 값의 다음 순열 -> 순열 만들어주는 함수 사용
*/
using namespace std;

int T; // tc개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>> T;
    
    for(int t=0;t<T; ++t){
        string st;
        cin>>st;
        if(next_permutation(st.begin(),st.end())) cout<< st<<"\n";
        else cout<<"BIGGEST\n";
        
    }
    return 0;
}