import java.io.*;
import java.util.*;

public class Main2 {
    static int [] addr(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a]+ret[b];
        return ret;
    }
    static int [] addi(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a]+b;
        return ret;
    }
    static int [] mulr(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a]*ret[b];
        return ret;
    }
    static int [] muli(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a]*b;
        return ret;
    }
    static int [] banr(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a]&ret[b];
        return ret;
    }
    static int [] bani(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a]&b;
        return ret;
    }
    static int [] borr(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a]|ret[b];
        return ret;
    }
    static int [] bori(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a]|b;
        return ret;
    }
    static int [] setr(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = ret[a];
        return ret;
    }
    static int [] seti(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = a;
        return ret;
    }
    static int [] gtir(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = (a>ret[b])?1:0;
        return ret;
    }
    static int [] gtri(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = (ret[a]>b)?1:0;
        return ret;
    }
    static int [] gtrr(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = (ret[a]>ret[b])?1:0;
        return ret;
    }
    static int [] eqir(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = (a==ret[b])?1:0;
        return ret;
    }
    static int [] eqri(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = (ret[a]==b)?1:0;
        return ret;
    }
    static int [] eqrr(){
        int [] ret = Arrays.copyOf(before,before.length);
        ret[c] = (ret[a]==ret[b])?1:0;
        return ret;
    }
    static int [] before = new int[4];
    static int [] after = new int[4];
    static int a,b,c,op;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = 778,cnt=0;
        while(n-->0) {
            int cnt2 = 0;
            String[] tok = br.readLine().split(" ");
            String [] tok2 = br.readLine().split(" ");
            op = Integer.parseInt(tok2[0]);
            a = Integer.parseInt(tok2[1]);
            b = Integer.parseInt(tok2[2]);
            c = Integer.parseInt(tok2[3]);
            String [] tok3 = br.readLine().split(" ");
            before[0]=Integer.parseInt(tok[1].substring(1,2));
            before[1]=Integer.parseInt(tok[2].substring(0,1));
            before[2]=Integer.parseInt(tok[3].substring(0,1));
            before[3]=Integer.parseInt(tok[4].substring(0,1));
            after[0]=Integer.parseInt(tok3[2].substring(1,2));
            after[1]=Integer.parseInt(tok3[3].substring(0,1));
            after[2]=Integer.parseInt(tok3[4].substring(0,1));
            after[3]=Integer.parseInt(tok3[5].substring(0,1));
            if(Arrays.equals(after,addr())) cnt2++;
            if(Arrays.equals(after,addi())) cnt2++;
            if(Arrays.equals(after,mulr())) cnt2++;
            if(Arrays.equals(after,muli())) cnt2++;
            if(Arrays.equals(after,banr())) cnt2++;
            if(Arrays.equals(after,bani())) cnt2++;
            if(Arrays.equals(after,borr())) cnt2++;
            if(Arrays.equals(after,bori())) cnt2++;
            if(Arrays.equals(after,setr())) cnt2++;
            if(Arrays.equals(after,seti())) cnt2++;
            if(Arrays.equals(after,gtir())) cnt2++;
            if(Arrays.equals(after,gtri())) cnt2++;
            if(Arrays.equals(after,gtrr())) cnt2++;
            if(Arrays.equals(after,eqir())) cnt2++;
            if(Arrays.equals(after,eqri())) cnt2++;
            if(Arrays.equals(after,eqrr())) cnt2++;
            if(cnt2>2) cnt++;
            String buf = br.readLine();
        }
        System.out.println(cnt);
    }
}
