import java.util.*;
import java.io.*;

public class p614 {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Long> forwards = new ArrayList<>(), backwards = new ArrayList<>(); 
        try {
            String inp = in.readLine();
            while (inp != null) {
                String[] input = inp.split(" ");
                int trainLength = Integer.parseInt(input[0]), platSize = Integer.parseInt(input[1]);
                if (trainLength == 0 && platSize == 0) break;

                input = in.readLine().split(" ");
                ArrayList<Integer> plat = new ArrayList<>(platSize);
                for (String num: input) plat.add(Integer.parseInt(num));
                
                forwards.add(0L);
                long distanceTraveled = 0, passengers = 0;
                for (int i = 0; i < plat.size() - trainLength; ++i) {
                    passengers += plat.get(i);
                    distanceTraveled += passengers;
                    forwards.add(distanceTraveled);
                }

                distanceTraveled = 0L; passengers = 0L;

                backwards.add(0L);  
                for (int j = plat.size() - 1; j >= trainLength; --j) {
                    passengers += plat.get(j);
                    distanceTraveled += passengers; 
                    backwards.add(distanceTraveled);
                }

                long min = Long.MAX_VALUE; 
                int i = 0, j = backwards.size()-1;
                while (i < backwards.size()) {
                    min = Math.min(min, forwards.get(i) + backwards.get(j));
                    ++i;
                    --j;
                }
                
                if (min == Long.MAX_VALUE) min = 0;
                System.out.println(min); 
                inp = in.readLine();
                forwards.clear(); backwards.clear();
            }
        } catch (Exception e) {e.printStackTrace();}
    }
}
