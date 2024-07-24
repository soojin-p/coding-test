import java.util.*;
import java.io.*;

 class Main {
    static class Virus {
        int r, c, time;

        Virus(int r, int c, int time) {
            this.r = r;
            this.c = c;
            this.time = time;
        }
    }

    static int N, M;
    static int[][] lab;
    static int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    static List<Virus> viruses = new ArrayList<>();
    static Virus[] activated;
    static int minTime = Integer.MAX_VALUE;
    static int emptySpace = 0;

    public static void main(String[] args)throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer  st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        lab = new  int[N][N];
        activated = new Virus[M];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j =0; j<N; j++){
                lab[i][j] = Integer.parseInt(st.nextToken());
                if(lab[i][j] == 2){
                    viruses.add(new Virus(i, j, 0));
                }else if(lab[i][j]==0) emptySpace ++;
            }

        }

        if(emptySpace ==0){
            System.out.println(0);
            return;
        }

        selectVirus(0,0);
        System.out.println(minTime == Integer.MAX_VALUE ? -1 : minTime);
        return;
    }

    static void selectVirus(int start, int selectCnt) {
        if (selectCnt == M) {
            simulation();
            return;
        }

        for (int i = start; i < viruses.size(); i++) {
            activated[selectCnt] = viruses.get(i);
            selectVirus(i + 1, selectCnt + 1);
        }
    }

    static void simulation(){
        Queue<Virus> queue = new LinkedList<>();
        boolean[][] visited = new boolean[N][N];
        int infected =0;

        for(Virus virus : activated){
            visited[virus.r][virus.c] = true;
            queue.add(virus);
        }

        while (!queue.isEmpty()) {
            Virus curVirus = queue.poll();
           
            for(int[] d: dir){
                int nr = curVirus.r + d[0];
                int nc = curVirus.c + d[1];

                if(isValid(visited, nr,nc)&& lab[nr][nc] !=1){
                    if(lab[nr][nc]==0) infected++;
                    if(infected== emptySpace){
                        minTime = Math.min(minTime, curVirus.time+1);
                        return;
                    }  
                    visited[nr][nc] =true;
                    queue.add(new Virus(nr, nc, curVirus.time+1));
                }
            }
        }
    }

    static boolean isValid(boolean[][] visited, int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < N && !visited[r][c];
    }
}