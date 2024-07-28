import java.util.LinkedList;
import java.util.Queue;

class Solution {
    // A-B가 연결되어 있고 B-C가 연결되어 있으면, A,B,C는 같은 네트워크
    // n: 컴퓨터 개수, computers: 연결 정보가 담긴 배열
    // 네트워크 개수 반환하는 문제.

    //  배열을 탐색하면서 네트워크 연결, 네트워크 연결이 끝나면 1개의 네트워크 생성.
    // bfs vs dfs => 모든 배열을 탐색 해야하므로 dfs가 간단할 듯함
   
    public int solution(int n, int[][] computers) {
        int answer = 0;

        boolean[] visited = new boolean[n];

        for(int i=0 ; i< n; i++){
            if(!visited[i]){
                dfs(computers, visited, n, i); // 네트워크 연결
                answer++;
            }
        }
        return answer;
    }
    private void dfs(int[][] computers, boolean[] visited ,int n, int start){
        visited[start] = true;
        
        for(int i=0; i<n; i++){
            if(!visited[i] && computers[start][i]==1){
                dfs(computers, visited, n, i);
            }
        }
    }
}