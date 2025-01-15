import java.io.*;
import java.util.*;

public class Solution {
    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int distance(Point other) {
            return Math.abs(this.x - other.x) + Math.abs(this.y - other.y);
        }
    }

    static int N;
    static Point company, home;
    static Point[] customers;
    static boolean[] visited;
    static int minDistance;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine()); // 테스트 케이스 수

        for (int tc = 1; tc <= T; tc++) {
            N = Integer.parseInt(br.readLine()); // 고객 수
            String[] input = br.readLine().split(" "); // 좌표 입력 한 줄 읽기

            // 회사와 집 좌표 읽기
            company = new Point(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
            home = new Point(Integer.parseInt(input[2]), Integer.parseInt(input[3]));

            // 고객 좌표 읽기
            customers = new Point[N];
            for (int i = 0; i < N; i++) {
                int x = Integer.parseInt(input[4 + i * 2]);
                int y = Integer.parseInt(input[5 + i * 2]);
                customers[i] = new Point(x, y);
            }

            visited = new boolean[N];
            minDistance = Integer.MAX_VALUE;

            // 순열 탐색 시작
            findRoute(company, 0, 0);

            // 결과 출력
            System.out.println("#" + tc + " " + minDistance);
        }
    }

    static void findRoute(Point current, int count, int distance) {
        if (distance >= minDistance) return;

        if (count == N) {
            distance += current.distance(home);
            minDistance = Math.min(minDistance, distance);
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                findRoute(customers[i], count + 1, distance + current.distance(customers[i]));
                visited[i] = false;
            }
        }
    }
}
