#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool visited[26];
int board[20][20];

int ans = 0;
int R, C;

void dfs(int x, int y,int cnt) {
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < R && ny >= 0 && ny < C && visited[board[nx][ny]] == false) {
			visited[board[nx][ny]] = true;
			dfs(nx, ny, cnt + 1);
			visited[board[nx][ny]] = false;
		}
	}

}
int main() {
	
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < C; j++) {
			int n = st[j] - 'A';
			board[i][j] = n;
		}
	}
	visited[board[0][0]] = true;
	dfs(0, 0, 1);
	cout << ans;
	return  0;
}