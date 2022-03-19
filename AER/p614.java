import java.util.*;
import java.io.*;

public class p614 {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out)); 
        try {
            String inp = in.readLine();
            while (inp != null) {
                String[] input = inp.split(" ");
                int trainLength = Integer.parseInt(input[0]), platSize = Integer.parseInt(input[1]);
                input = in.readLine().split(" ");
                ArrayList<Integer> plat = new ArrayList<>(platSize);
                for (String num: input) plat.add(Integer.parseInt(num));
                
            }
        } catch (Exception e) {e.printStackTrace();}
    }
}
