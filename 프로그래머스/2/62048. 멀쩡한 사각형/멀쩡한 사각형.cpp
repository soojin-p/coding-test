using namespace std;
long long gcd(long long a, long long b){
    while(b!=0){
        long long tmp = a%b;
        a=b;
        b=tmp;
    }
    return a;
}
long long solution(int w,int h) {
    long long answer = 1;
    
    long long W = w;  // w를 long long으로 변환
    long long H = h;  // h를 long long으로 변환
    answer = (W * H) - (W + H - gcd(W, H));
    return answer;
}