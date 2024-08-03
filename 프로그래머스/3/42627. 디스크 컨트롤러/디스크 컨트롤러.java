import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    //작업이 요청되는 시점, 작업의 소요시간
    public int solution(int[][] jobs) {
        int sum = 0;
        int curTime = 0;
        int idx = 0;

        // 요청시간 기준으로 정렬
        Arrays.sort(jobs, Comparator.comparingInt(o -> o[0]));
        // 작업 소요시간 기준으로 정렬하는 우선순위 큐
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[1]));

        while (idx < jobs.length || !pq.isEmpty()) {
            // 현재시간보다 작거나 같은 작업을 큐에 넣어줌
            while (idx < jobs.length && jobs[idx][0] <= curTime) {
                pq.add(jobs[idx++]);
            }
            if (pq.isEmpty()) { // 작업이 들어오지 않은 경우
                curTime++;
            } else { // 작업이 있는 경우
                int[] cur = pq.poll();
                sum += cur[1] + curTime - cur[0];
                curTime += cur[1];
            }
        }
        return sum / jobs.length;
    }
}