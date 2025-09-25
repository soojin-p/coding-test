#include  <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> book(N+1);
    for (int i = 1; i <= N; i++) cin >> book[i]; 
    
    int num=N;
    for(int i=N; i>0;i--){
        if(book[i]==num) num--;
    }
    cout << num;
    return 0;
}