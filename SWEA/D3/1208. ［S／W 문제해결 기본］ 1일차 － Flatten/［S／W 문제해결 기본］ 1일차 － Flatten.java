
import java.util.*;


public class Solution {
	// 제한된 횟수만큼 옮기는 작업을 한 후 최고점과 최저점의 차이를 반환하
	// 모든 경우의 수 탐색
	// DFS
	static HashMap<String, Boolean> visited = new HashMap<>();
	static int maxval=Integer.MIN_VALUE, minval=Integer.MAX_VALUE;
	public static void main(String args[]) throws Exception
	{
	
		Scanner sc = new Scanner(System.in);
		int T = 10;
		
		int []block = new int[100];
		for(int t=1; t<=T; t++) {
			
			int dump = sc.nextInt();
			
			for(int i=0; i<100; i++) {
				block[i] = sc.nextInt();
			}
			// 블럭에서 제일 높은 부부늘 찾음,
			// 블럭에서 제일 낮은 부부늘 찾음 
			// 겨환
			
			for(int i=0; i<dump; i++) {
				int maxidx =0, minidx=0;
				
				for(int j=0; j<100; j++) {
					if(block[j]>block[maxidx]) maxidx= j;
					if(block[j]<block[minidx]) minidx= j;
				}
				block[maxidx]--;
				block[minidx]++;
				
				if(block[maxidx]-block[minidx]<=1) break;
			}
			int maxval = Arrays.stream(block).max().getAsInt()	;
			int minval = Arrays.stream(block).min().getAsInt()	;
			
			System.out.println("#"+t+" "+ (maxval-minval));
		}
		
	}
	
}
