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

        // 연구소의 크기를 입력받고
        N = sc.nextInt();
        M = sc.nextInt();

        lab = new int[N][M];

        // 바이러스, 벽, 빈칸 위치를 배열에 저장.
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
        // 벽 세우기
        buildWalls(0, 0);
        System.out.println(maxSafeZone);
    }

    static void buildWalls(int start, int count) {
        if (count == 3) {
            // 벽을 3개 세우면 바이러스 확산
            spreadvirus();
            return;
        }

        for (int i = start; i < empty.size(); i++) {
            int[]  pos = empty.get(i);
            
                lab[pos[0]][pos[1]] = 1;
                buildWalls( i+1,count + 1);
                lab[pos[0]][pos[1]]= 0;
        }
    }

    static void spreadvirus() { // 바이러스 확산
       
        int[][] grid = new int[N][M];
        for (int i = 0; i < N; i++) {
            grid[i] = lab[i].clone();
        }

        boolean[][] visited = new boolean[N][M];
        for (int[] pos : virus) {
            dfs(grid, visited, pos[0], pos[1]);
        }
        countSafedZone(grid);
    }

    static boolean isValid(int[][] grid, int r, int c) {
        return (r >= 0 && r < N && c >= 0 && c < M && grid[r][c] == 0);
    }

    static void dfs(int[][] grid,boolean[][] visited, int r, int c) {
        
        visited[r][c] = true; 
        grid[r][c] = 2;
        for (int[] d : dir) {
            int nextRow = r + d[0];
            int nextCol = c + d[1];

            if (isValid(grid, nextRow, nextCol)&& !visited[nextRow][nextCol]) {
                grid[nextRow][nextCol] = 2;
                dfs(grid,visited, nextRow, nextCol);
            }
        }
    }

    static void countSafedZone(int grid[][]) { // 안전구역 계산
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
