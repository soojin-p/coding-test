import java.util.*;
import java.io.*;

class Main {

    static class Pos {
        int r, c, dist;

        Pos(int r, int c, int dist) {
            this.r = r;
            this.c = c;
            this.dist = dist;
        }

        // Overriding equals and hashCode to ensure Pos objects can be used in HashSet
        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Pos pos = (Pos) obj;
            return r == pos.r && c == pos.c;
        }

        @Override
        public int hashCode() {
            return Objects.hash(r, c);
        }
    }

    static class Ball {
        Pos red, blue;

        Ball(Pos red, Pos blue) {
            this.red = red;
            this.blue = blue;
        }

        // Overriding equals and hashCode to ensure Ball objects can be used in HashSet
        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Ball ball = (Ball) obj;
            return red.equals(ball.red) && blue.equals(ball.blue);
        }

        @Override
        public int hashCode() {
            return Objects.hash(red, blue);
        }
    }

    static int N, M;
    static char[][] board;
    static Pos redPos, bluePos;
    static int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new char[N][M];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = line.charAt(j);
                if (board[i][j] == 'R') redPos = new Pos(i, j, 0);
                if (board[i][j] == 'B') bluePos = new Pos(i, j, 0);
            }
        }
        boolean result = bfs();
        System.out.println(result ? 1 : 0);
    }

    static boolean bfs() {
        Queue<Ball> queue = new ArrayDeque<>();
        Set<Ball> visited = new HashSet<>();

        queue.add(new Ball(redPos, bluePos));
        visited.add(new Ball(redPos, bluePos));
        int count = 0;
        while (!queue.isEmpty() && count++ < 10) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Ball cur = queue.poll();

                for (int[] d : dir) {
                    Pos nextR = move(cur.red, d);
                    Pos nextB = move(cur.blue, d);

                    if (board[nextB.r][nextB.c] == 'O')
                        continue;
                    if (board[nextR.r][nextR.c] == 'O')
                        return true;
                    if (nextR.r == nextB.r && nextR.c == nextB.c) {
                        if (nextR.dist > nextB.dist) {
                            nextR.r -= d[0];
                            nextR.c -= d[1];
                        } else {
                            nextB.r -= d[0];
                            nextB.c -= d[1];
                        }
                    }

                    Ball next = new Ball(nextR, nextB);
                    if (!visited.contains(next)) {
                        visited.add(next);
                        queue.add(next);
                    }
                }
            }
        }
        return false;
    }

    static Pos move(Pos start, int[] d) {
        int r = start.r;
        int c = start.c;
        int dist = 0;

        while (isValid(r + d[0], c + d[1]) && board[r + d[0]][c + d[1]] != '#') {
            r += d[0];
            c += d[1];
            dist++;
            if (board[r][c] == 'O') break;
        }
        return new Pos(r, c, dist);
    }

    static boolean isValid(int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    }
}
