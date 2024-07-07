class Solution {
    private int answer = 0;
    public int solution(int k, int[][] dungeons) {
       
        boolean[] visited = new boolean[dungeons.length];
        backtrack( k, dungeons, visited, 0);    
        return answer;
    }

    private void backtrack(int k, int[][] dungeons, boolean[] visited, int cnt){
       
        for(int i=0; i<dungeons.length;i++){
            //탐험 가능한 조건
            if(dungeons[i][0]<=k && !visited[i]){ 
                visited[i]=true;
                backtrack(k-dungeons[i][1], dungeons, visited, cnt+1);
                visited[i]=false;
            }
        }
         answer = Math.max(answer, cnt);
    }   
}
