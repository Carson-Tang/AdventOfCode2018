import java.io.*;
import java.util.*;
public class main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int min = Integer.MAX_VALUE;
        for(int i = 65; i <= 90; i++){
            min = Math.min(min,f(s,(char)i,(char)(i+32)));
        }
        System.out.println(min);
    }
    public static int f(String s, char a, char b){
        Stack<Character> st = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i)==a||s.charAt(i)==b)continue;
            if(st.empty()) st.push(s.charAt(i));
            else if (Math.abs(st.peek()-s.charAt(i))==32) st.pop();
            else st.push(s.charAt(i));
        }
        return st.size();
    }
}
