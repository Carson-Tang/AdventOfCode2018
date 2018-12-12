import java.io.*;
import java.util.*;

public class main {
    static Scanner sc;
    static int ans;
    public static void main (String [] args)throws IOException {
        sc = new Scanner(System.in);
        ArrayList<Integer>l = new ArrayList<>();
        ans = recur(sc.nextInt(),sc.nextInt(),l);
        System.out.println(ans);
    }
    static int recur(int child, int data, ArrayList<Integer>l){
        int value = 0;
        for(int i = 0; i < child; i++) {
            int nextchild = sc.nextInt();
            int nextdata = sc.nextInt();
            ArrayList<Integer>l2 = new ArrayList<>();
            l.add(recur(nextchild, nextdata,l2));
        }
        if(child==0) {
            for(int i = 0; i < data; i++) value += sc.nextInt();
            return value;
        } else {
            for(int i = 0; i < data; i++){
                int idx = sc.nextInt();
                if(idx<=l.size()) value += l.get(idx-1);
            } return value;
        }
    }
}
