#include <iostream>
#include <string>
using namespace std;

// 팰린드롬인지 확인
bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int n = s.length();

    for (int i = 0; i < n; ++i) {
        if (isPalindrome(s, i, n - 1)) {
            // 앞쪽 i개만 뒤에 붙임
            cout << n + i << '\n';
            return 0;
        }
    }

    return 0;
}
