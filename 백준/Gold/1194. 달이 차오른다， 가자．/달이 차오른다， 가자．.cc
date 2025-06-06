#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
char board[50][50];
bool visited[50][50][64];
int dir[4][4] = { {-1,0},{1,0},{ 0,-1},{0,1} };
bool isValid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}
int bfs(int x, int y) {
	queue<tuple<int, int, int, int>> q;
	q.push({ x, y, 0, 0 });
	visited[x][y][0] = true;
	while (!q.empty()) {
		auto [cx, cy, key, cnt] = q.front(); q.pop();

		if (board[cx][cy] == '1') return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = cx+ dir[i][0];
			int ny = cy+ dir[i][1];
			int nkey = key;

			if (!isValid(nx, ny) || board[nx][ny] == '#') continue;
			if ('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
				nkey |= (1 << (board[nx][ny] - 'a'));
			}
			if ('A' <= board[nx][ny] && board[nx][ny] <='F') {
				if((nkey & (1<<board[nx][ny]-'A'))==0) continue;
			}
			if (!visited[nx][ny][nkey]) {
				q.push({ nx, ny, nkey, cnt + 1 });
				visited[nx][ny][nkey] = true;
			}
			
		}
	}
	return -1;
}
int main() {
	int cx, cy;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0') {
				cx = i;
				cy = j;
			}
		}
	}
	cout<< bfs(cx, cy);
	return 0;
}