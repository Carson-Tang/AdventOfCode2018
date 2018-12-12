import java.io.*;
import java.util.*;
public class main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        Stack<Character> st = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            if(st.empty()) st.push(s.charAt(i));
            else if (Math.abs(st.peek()-s.charAt(i))==32) st.pop();
            else st.push(s.charAt(i));
        }
        System.out.println(st.size());
    }
}
