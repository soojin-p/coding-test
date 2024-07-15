import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;

        long sum1 = Arrays.stream(queue1).sum();
        long totalSum = Arrays.stream(queue1).sum()+ Arrays.stream(queue2).sum();

        if (totalSum % 2 != 0) return -1;

        long target = totalSum / 2;
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();

        for (int num : queue1) q1.offer(num);
        for (int num : queue2) q2.offer(num);

        // 합이 목표합과 같아질 때가지 반복
        int maxOperation = (queue1.length + queue2.length) * 2; 
        while (sum1 != target) {
             if (answer > maxOperation) return -1;
   
            if (sum1 > target) {
                int num = q1.poll();
                q2.offer(num);
                sum1 -= num;
            } else {
                int num = q2.poll();
                q1.offer(num);
                sum1 += num;
            }
            answer++;
           
        }
        return answer;
    }
}