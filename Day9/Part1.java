import java.io.*;
import java.util.*;

public class Main {
    public static void main (String [] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] tok = br.readLine().split(" ");
        int p = Integer.parseInt(tok[0]), point = Integer.parseInt(tok[6]);
        int id = 0, curridx = 0, ans = 0; int [] arr = new int[477];
        ArrayList<Integer>marble = new ArrayList<>();
        marble.add(0);
        for(int i = 1; i <= point; i++){
            id++;
            if(id==p+1) id = 1;
            if(i%23==0){
                arr[id]+=i;
                curridx-=7;
                if(curridx<0) curridx+=marble.size();
                arr[id]+=marble.get(curridx);
                marble.remove(curridx);
            } else {
                curridx += 2;
                if (curridx > marble.size()) curridx = 1;
                if(curridx>marble.size()) marble.add(i);
                else marble.add(curridx, i);
            }
        }
        for(int i = 1; i <= 476; i++) ans = Math.max(ans,arr[i]);
        System.out.println(ans);
    }
}
