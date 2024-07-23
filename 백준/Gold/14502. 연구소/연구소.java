
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    // 입력:
    // int 형 N M, string형 M 사이즈 문자열

    // 빈칸 3개의 위치를 골라 벽을 만들기 실행
    // 전체 경우의 수를 고려하여 바이러스가 퍼졌을 때,
    // 안전영의 최대값 구하기.

    static int N, M;
    static int[][] lab;
    static int[][] DIR = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };

    static ArrayList<int[]> virus = new ArrayList<>();
    static ArrayList<int[]> empty = new ArrayList<>();

    static int maxSafezone = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        lab = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(reader.readLine());
            for (int j = 0; j < M; j++) {
                lab[i][j] = Integer.parseInt(st.nextToken());
                if (lab[i][j] == 2)
                    virus.add(new int[] { i, j });
                else if (lab[i][j] == 0)
                    empty.add(new int[] { i, j });
            }
        }
        buildWall(0, 0);
        System.out.println(maxSafezone);
    }
    
    static void buildWall(int start, int count) {

        if (count == 3) {
            virusSimulation();
            return;
        }
        for (int i = start; i < empty.size(); i++) {
            int[] pos = empty.get(i);
            lab[pos[0]][pos[1]] = 1;
            buildWall(i+1, count + 1);
            lab[pos[0]][pos[1]] = 0;
        }
    }


    static void virusSimulation() {
        int[][] temp = new int[N][M];

        for (int i = 0; i < N; i++) {
            temp[i] = lab[i].clone();
        }

        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[N][M];

        for (int[] pos : virus) {
            queue.add(pos);
            visited[pos[0]][pos[1]] = true;
        }
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int curRow = cur[0];
            int curCol = cur[1];

            for (int[] dir : DIR) {
                int nextRow = curRow + dir[0];
                int nextCol = curCol + dir[1];
                if (isValid(temp, nextRow, nextCol) && !visited[nextRow][nextCol] && temp[nextRow][nextCol]==0) {
                    temp[nextRow][nextCol] = 2;
                    visited[nextRow][nextCol] = true;
                    queue.add(new int[] { nextRow, nextCol });           
                }
            }
        }
        countSafezone(temp);
    }

    static void countSafezone(int[][] grid) {
        int safezone =0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0)
                    safezone++;
            }
        }
        maxSafezone = Math.max(maxSafezone, safezone);
    }
    static boolean isValid(int[][] grid, int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    }

}