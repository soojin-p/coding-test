#include <iostream>
#include <string>

using namespace std;

#define PRINT cout << tmp; line_length += tmp.size()
#define NEXTLINE cout << '\n'; line_length = 0

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string tmp = " ";
	int line_length = 0;

	while (cin >> tmp) {
		if (tmp.compare("<br>") == 0) {
			NEXTLINE;
		}
		else if (tmp.compare("<hr>") == 0) {
			if (line_length != 0) { NEXTLINE; }
			for (int i = 0; i < 80; i++) {
				cout << '-';
			}
			NEXTLINE;
		}
		else {
			if (line_length + tmp.size() < 80) {
				if (line_length != 0) { cout << ' '; line_length++; }
				PRINT;
			}
			else {
				NEXTLINE;
				PRINT;
			}
		}
	}

	return 0;
}