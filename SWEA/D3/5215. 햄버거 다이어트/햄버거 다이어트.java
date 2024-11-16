
import java.util.*;


public class Solution {
	// 정해진 칼로리 이하의 조합 중에서 점수가 높은 햄버거 조합을 구하느 문제
	// dfs

	

	public static void main(String args[]) throws Exception
	{
	
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=1; t<=T; t++) {
			int N = sc.nextInt(); // 재료의 수
			int L = sc.nextInt(); // 제한 칼로리
			
			 int[]  points= new int[N]; // 각 재료의 맛 점수
	         int[] calories = new int[N]; // 각 재료의 칼로리
			
	
			for(int i=0; i<N; i++) {
				points[i] = sc.nextInt();
				calories[i] = sc.nextInt();
				
				
			}
			 // DP 배열을 사용하여 제한 칼로리 내에서 최댓값을 계산
            int[] dp = new int[L + 1]; 
            
            for (int i = 0; i < N; i++) {
                int cal = calories[i];
                int point = points[i];

                // 칼로리 용량을 역순으로 갱신
                for (int j = L; j >= cal; j--) {
                    dp[j] = Math.max(dp[j], dp[j - cal] + point);
                }
            }

            // 결과 출력: 가장 큰 점수 출력
            System.out.println("#" + t + " " + dp[L]);
        }
	}
}
