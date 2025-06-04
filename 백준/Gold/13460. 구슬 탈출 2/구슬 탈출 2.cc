#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
// 상하좌우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char board[10][10];
queue<tuple<int, int, int,int, int>> q;
bool visited[10][10][10][10];

int tx, ty;


int bfs(int rx, int ry,int  bx,int by) {
	int cnt = 0;
	q.push({ rx, ry, bx, by, 0 });
	visited[rx][ry][bx][by] = true;
	while (!q.empty()) {
		auto [rx, ry, bx, by, cnt] = q.front(); q.pop();
		if (cnt >= 10) return -1;

		for (int i = 0; i < 4; i++) {
			int nrx = rx ;
			int nry = ry ;

			int nbx = bx ;
			int nby = by ;
			int rmove = 0, bmove = 0;

			while (board[nrx+dx[i]][nry+dy[i]] != '#' && board[nrx][nry] != 'O') {
				nrx += dx[i];
				nry += dy[i];
				rmove++;
				if (board[nrx][nry] == 'O') break;
			}
			while (board[nbx + dx[i]][nby + dy[i]] != '#' && board[nbx][nby] != 'O') {
				nbx += dx[i];
				nby += dy[i];
				bmove++;
				if (board[nbx][nby] == 'O') break;
			}
			
			if (board[nbx][nby] == 'O') continue;
			if (board[nrx][nry] == 'O') return cnt + 1;
			if (nrx == nbx && nry == nby) {
				if (rmove > bmove) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			if (!visited[nrx][nry][nbx][nby]) {
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx, nry, nbx, nby, cnt + 1 });
			}
		}


	}
	return -1;
}
int main() {
	cin >> n >> m;
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'O') {
				tx = i;
				ty = j;
			}
			if (board[i][j] == 'R') {
				rx = i; ry = j;
			}
			if (board[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}
	cout << bfs(rx, ry, bx, by);
	return 0;
}