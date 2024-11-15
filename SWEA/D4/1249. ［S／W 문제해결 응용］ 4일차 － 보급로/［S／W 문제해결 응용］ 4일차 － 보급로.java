import java.util.*;
import java.io.FileInputStream;

class Solution {
    public static class Node implements Comparable<Node> {
        int x, y, cost;
        
        Node(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
        
        public int compareTo(Node other) {
            return this.cost - other.cost;
        }
    }

    public static int minRepairTime(int[][] map, int N) {
        int[][] repairTime = new int[N][N];
        for (int[] row : repairTime) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(0, 0, map[0][0]));
        repairTime[0][0] = map[0][0];
        
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            int x = cur.x, y = cur.y, cost = cur.cost;

            if (x == N - 1 && y == N - 1) return cost;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    int newCost = cost + map[nx][ny];

                    if (newCost < repairTime[nx][ny]) {
                        repairTime[nx][ny] = newCost;
                        pq.add(new Node(nx, ny, newCost));
                    }
                }
            }
        }
        return -1;
    }
    
    public static void main(String args[]) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            int N = sc.nextInt();
            int[][] map = new int[N][N];
            
            for (int i = 0; i < N; i++) {
                String line = sc.next();
                for (int j = 0; j < N; j++) {
                    map[i][j] = line.charAt(j) - '0';
                }
            }

            int result = minRepairTime(map, N);
            System.out.println("#" + test_case + " " + result);
        }

        sc.close();
    }
}
