import java.io.*;
import java.util.*;

public class Main {
    static class node{ long val; node l = null, r = null;}
    public static void main (String [] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tok = br.readLine().split(" ");
        long [] arr = new long[477]; long ans = 0; int id = 1;
        long p = Integer.parseInt(tok[0]), point = Integer.parseInt(tok[6]);
        node cur = new node(); node cur1 = new node();
        cur.val = 0; cur1.val = 1;
        cur.r = cur1; cur.l = cur1;
        cur1.r = cur; cur1.l = cur;
        cur = cur1;
        for(long i = 2; i <= point*100; i++){
            id++;
            if(id==p+1) id = 1;
            if(i%23==0){
                arr[id] += i;
                arr[id] += cur.l.l.l.l.l.l.l.val;
                cur.l.l.l.l.l.l.l.l.r = cur.l.l.l.l.l.l;
                cur.l.l.l.l.l.l.l = cur.l.l.l.l.l.l.l.l;
                cur = cur.l.l.l.l.l.l;
            } else {
                node next = new node();
                next.val = i;
                cur.r.r.l = next;
                next.l = cur.r;
                next.r = cur.r.r;
                cur.r.r = next;
                cur = cur.r.r;
            }
        }
        for(int i = 1; i <= 476; i++) ans = Math.max(ans,arr[i]);
        System.out.println(ans);
    }
}

