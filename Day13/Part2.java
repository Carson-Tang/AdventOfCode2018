import java.io.*;
import java.util.*;

public class main {
    static class cart {
        int idx,dir,cnt;
        boolean car;
        cart(int idx, int dir, int cnt, boolean car){
            this.idx=idx;
            this.dir=dir;
            this.cnt=cnt;
            this.car=car;
        }
    }
    static char [][] g;
    static cart [][] v;
    static int [][] d = {{-1,0},{1,0},{0,-1},{0,1}};
    static int carcnt;
    static void move(int x, int y){
        cart cur = v[x][y];
        int nextx = x+d[cur.dir][0];
        int nexty = y+d[cur.dir][1];
        if(carcnt==1){
            System.out.println(nexty+","+nextx);
            System.exit(0);
        }
        if(v[nextx][nexty].car){
            carcnt-=2;
            v[nextx][nexty]=new cart(0,0,0,false);
            return;
        }
        cur.cnt++;
        char next = g[nextx][nexty];
        if (next=='/'){
            if(cur.dir==0) cur.dir=3;
            else if (cur.dir==1) cur.dir=2;
            else if (cur.dir==2) cur.dir=1;
            else if(cur.dir==3) cur.dir=0;
        } else if (next=='\\'){
            if(cur.dir==0) cur.dir=2;
            else if (cur.dir==1) cur.dir=3;
            else if (cur.dir==2) cur.dir=0;
            else if(cur.dir==3) cur.dir=1;
        } else if (next=='+'){
            if(cur.idx==0){
                if(cur.dir==0) cur.dir=2;
                else if (cur.dir==1) cur.dir=3;
                else if (cur.dir==2) cur.dir=1;
                else if (cur.dir==3) cur.dir=0;
            } else if (cur.idx==2){
                if(cur.dir==0) cur.dir=3;
                else if(cur.dir==1) cur.dir=2;
                else if(cur.dir==2) cur.dir=0;
                else if(cur.dir==3) cur.dir=1;
            }
            cur.idx = (cur.idx+1)%3;
        }
        v[nextx][nexty]=cur;
    }
    public static void main (String [] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        g = new char[150][150];
        v = new cart[150][150];
        carcnt=0;
        // UP - 0 | DOWN - 1 | LEFT - 2 | RIGHT - 3
        for(int i = 0; i < 150; i++){
            String s = br.readLine();
            for(int j = 0; j < 150; j++){
                g[i][j] = s.charAt(j);
                v[i][j]=new cart(0,0,0,false);
                if(g[i][j]=='^'){
                    g[i][j]='|';
                    v[i][j]=new cart(0,0,0,true);
                    carcnt++;
                } else if (g[i][j]=='v'){
                    g[i][j]='|';
                    v[i][j]=new cart(0,1,0,true);
                    carcnt++;
                } else if(g[i][j]=='>'){
                    g[i][j]='-';
                    v[i][j]=new cart(0,3,0,true);
                    carcnt++;
                } else if(g[i][j]=='<'){
                    g[i][j]='-';
                    v[i][j]=new cart(0,2,0,true);
                    carcnt++;
                }
            }
        }
        int cnt = 0;
        while(true){
            for(int i = 0; i < 150; i++){
                for(int j = 0; j < 150; j++){
                    if(v[i][j].car&&v[i][j].cnt==cnt){
                        move(i,j);
                        v[i][j]=new cart(0,0,0,false);
                    }
                }
            }
            cnt++;
        }
    }
}
