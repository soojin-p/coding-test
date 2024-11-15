
import java.util.*;


public class Solution {
	// N*N 보드에 N개의 퀸을 서로 다른 두 퀸이 공격하지 못하게 놓는 경우의 수
	// 모든 경우의 수 탐색 퀸 배치 -> 경우의 수 계산 -> 복구
	// 퀸 이동거리 검사
	// 백트랙킹
	 static int count; // 퀸을 배치하는 경우의 수
	public static void main(String args[]) throws Exception
	{
	
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=1; t<=T; t++) {
			int N = sc.nextInt();
            count = 0;
			int[] board = new int[N]; // 각 행의 퀸 위치를 저장 (board[row] = col)
			findqueuenspot(board, 0, N);
			
            System.out.println("#" + t + " " + count);
		}
		
	}
	public static void findqueuenspot(int[] board, int row, int n) {
		if(row == n) {
			count++;
			return;
		}
		
		for(int col=0; col<n; col++) {
			if(isVaild(board,row,col)) {
				board[row]= col;
				findqueuenspot(board,row+1,n);
			}
		}
		
	}
	static boolean isVaild(int[] board, int row, int col) {
		
		for(int i=0; i< row; i++) {
			 // 같은 열에 있거나 대각선에 있는지 검사
			if(board[i]==col || Math.abs(board[i]-col)== Math.abs(i-row)) {
				return false;
			}
		}
		return true;
	}
	
}
