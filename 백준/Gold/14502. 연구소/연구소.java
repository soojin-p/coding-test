import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int N;
    static int M;
    static int maxSafeZone = 0;
    static int[][] lab;
    static int[][] dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    static List<int[]> virus = new ArrayList<>();
    static List<int[]> empty = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        lab = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                lab[i][j] = sc.nextInt();
                if (lab[i][j] == 2) {
                    virus.add(new int[] { i, j });
                } else if (lab[i][j] == 0) {
                    empty.add(new int[] { i, j });
                }
            }
        }
        buildWalls(0, 0);
        System.out.println(maxSafeZone);
    }

    static void buildWalls(int start, int count) {
        if (count == 3) {
            spreadvirus();
            return;
        }

        for (int i = start; i < empty.size(); i++) {
            int[] pos = empty.get(i);
            lab[pos[0]][pos[1]] = 1;
            buildWalls(i + 1, count + 1);
            lab[pos[0]][pos[1]] = 0;
        }
    }

    static void spreadvirus() {
        int[][] grid = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = lab[i][j];
            }
        }

        boolean[][] visited = new boolean[N][M];
        for (int[] pos : virus) {
            dfs(grid, visited, pos[0], pos[1]);
        }
        countSafeZone(grid);
    }

    static boolean isValid(int[][] grid, boolean[][] visited, int r, int c) {
        return (r >= 0 && r < N && c >= 0 && c < M && grid[r][c] == 0 && !visited[r][c]);
    }

    static void dfs(int[][] grid, boolean[][] visited, int r, int c) {
        visited[r][c] = true;
        grid[r][c] = 2;
        for (int[] d : dir) {
            int nextRow = r + d[0];
            int nextCol = c + d[1];
            if (isValid(grid, visited, nextRow, nextCol)) {
                dfs(grid, visited, nextRow, nextCol);
            }
        }
    }

    static void countSafeZone(int[][] grid) {
        int safeZone = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0) {
                    safeZone++;
                }
            }
        }
        maxSafeZone = Math.max(maxSafeZone, safeZone);
    }
}
