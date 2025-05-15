#include<iostream>
#include<string>

using namespace std;

int isPikachu(string& s, int i) {

    if (s.substr(i, 2) == "pi") return 2;
    if (s.substr(i, 2) == "ka") return 2;
    if (s.substr(i, 3) == "chu") return 3;
    return 0;
}
int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    bool ans = true;

    int i = 0;
    while (i < s.length()) {
        int ck = isPikachu(s, i);
        if (ck == 0) {
            ans = false;
            break;
        }
        i += ck;
    }
  
    cout << (ans ? "YES" : "NO");
    return 0;
}