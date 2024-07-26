import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Solution
 */
class Solution {
    // 주식 가격, 정수 배열 prices가 입력으로 들어옴.
    // 현재 값보다 낮은 값이 있을 때 까지의 시간 구하기.
    // 현재 값보다 작은 값을 만나면 비교

    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < prices.length; i++) {
            while (!stack.isEmpty() && prices[stack.peek()] > prices[i]) {
                int index = stack.pop();
                answer[index] = i - index;
            }
            stack.push(i);
        }
        while (!stack.isEmpty()) {
            int index = stack.pop();
            answer[index] = prices.length - 1 - index;
        }
        return answer;
    }
}