import java.io.*;
import java.util.*;

public class main {
    static Scanner sc;
    static int sum;
    public static void main (String [] args)throws IOException {
        sc = new Scanner(System.in);
        recur(sc.nextInt(),sc.nextInt());
        System.out.println(sum);
    }
    static void recur(int child, int data){
        for(int i = 0; i < child; i++) {
            int nextchild = sc.nextInt();
            int nextdata = sc.nextInt();
            recur(nextchild,nextdata);
        }
        for(int i = 0; i < data; i++) sum += sc.nextInt();
    }
}
