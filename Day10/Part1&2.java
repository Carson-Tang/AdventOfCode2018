import java.io.*;
import java.util.*;

public class Main {
    static class p {
        int x,y;
        p(int x, int y){ this.x=x; this.y=y; }
    }
    public static void main (String [] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = 350;
        p [] point = new p[352];
        p [] v = new p[352];
        boolean [][] g = new boolean[10000][10000];
        while(n-->0){
            String s = br.readLine();
            int x = Integer.parseInt(s.substring(s.indexOf('<')+1,s.indexOf(',')).trim());
            int y = Integer.parseInt(s.substring(s.indexOf(',')+1,s.indexOf('>')).trim());
            int vx = Integer.parseInt(s.substring(s.lastIndexOf('<')+1,s.lastIndexOf(',')).trim());
            int vy = Integer.parseInt(s.substring(s.lastIndexOf(',')+1,s.length()-1).trim());
            point[n] = new p(x,y);
            v[n] = new p(vx,vy);
        }
        for(int i = 0; i < 351; i++){
            try {g[point[i].x+(v[i].x*10007)][point[i].y+(v[i].y*10007)]=true;}
            catch(Exception e){}
        }
        for(int i = 0; i < 1000; i++){
            for(int j = 0; j < 1000; j++){
                System.out.print((g[j][i])?1:0);
            }
            System.out.println();
        }
    }
}
