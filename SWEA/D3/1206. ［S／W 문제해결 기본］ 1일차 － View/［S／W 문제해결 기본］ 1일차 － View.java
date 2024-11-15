
import java.util.*;


public class Solution {
	public static void main(String args[]) throws Exception
	{
		// 입력
		// 테스트 케이스 수
 		Scanner sc = new Scanner(System.in);
		int T=10;
		
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int N =  sc.nextInt(); // 건물의 개수
			int []building =  new int[N];
			
			for(int i=0; i<N; i++) {
				building[i] = sc.nextInt();
			}
			int cnt= 0 ;
			
			for(int i=2; i<N-2; i++) {
				int maxheight = Math.max(
						Math.max(building[i-1], building[i-2]), 
						Math.max(building[i+1], building[i+2])
						);
					
				if(building[i]>maxheight) {
					cnt += building[i] - maxheight;
				}
			}
			System.out.println("#"+test_case+" " +cnt);
		}
		 
	}
	
}
