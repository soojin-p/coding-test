
import java.util.*;


public class Solution {
	static int maxResult; // 가장 큰 결과갑 저장
	 static HashMap<String, Boolean> visited = new HashMap<>(); 
	
	public static void main(String args[]) throws Exception
	{
		//정해진 횟수만큼 숫자판을 교환했을 때 받을 수 있는 가장 큰 금액 출력
		// 숫자판의 모든 교환 조합을 탐색하며, 가능한 최대 값을 계산
		// DFS 탐색
	
 		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt(); // 테스트 케이스의 수
		
		for(int t = 1; t<=T; t++) {
			String number =  sc.next(); //숫자판
			int c = sc.nextInt(); // 교환횟수
			
			maxResult = 0;
			visited.clear(); // 방문 상태 초기화
			
			dfs(number,c);
			
			System.out.println("#"+t+" "+maxResult);
		}
		
	}

	static void dfs(String number, int c) {
		if(c==0) {
			maxResult = Math.max(maxResult, Integer.parseInt(number));
			return;
		}
		
		String state = number + "," + c;
		if(visited.containsKey(state)) return;
		visited.put(state, true);
		
		char[] chars = number.toCharArray(); // 숫자판을 문자 배열로 변환
		
		for(int i=0; i< chars.length-1; i++) {
			for(int j=i+1; j<chars.length; j++) {
				swqp(chars,i,j);
				dfs(new String(chars), c - 1); // 교환 후 DFS 재귀 호출
	            swqp(chars, i, j); // 원상 복구
			}
		}
	}
	public static void swqp(char[] chars, int i, int j) {
		char tmp = chars[i];
		chars[i] = chars[j];
		chars[j] =tmp;
	}
}
