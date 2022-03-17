import java.util.*;
import java.io.*;

public class p165 {
    public static void main(String[] args) {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            String n;
            boolean hyper = true; 
            while ((n = in.readLine()) != "-1") {
                if (Integer.parseInt(n) < 0) break;
                hyper = true; 
                for (int i = 0; i < n.length() && hyper; ++i) {
                    hyper = (int) (n.charAt(i) - '0') % 2 == 0;
                }
                if (hyper) out.write("SI\n");
                else out.write("NO\n");
            }
            out.flush(); 
        }
        catch (Exception e) {}
    }
}
