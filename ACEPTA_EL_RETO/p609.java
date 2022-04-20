import java.io.*;
import java.util.*;

public class p609 {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        try {
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
            String inp = in.readLine();
            while (inp != null) {
                String[] input = inp.split(" ");
                int numTorres = Integer.parseInt(input[1]);
                
                ArrayList<Integer> xDist = new ArrayList<>();
                ArrayList<Integer> yDist = new ArrayList<>();
                int x = 0, y = 0;

                for (int i = 0; i < numTorres; ++i) {
                    input = in.readLine().split(" ");
                    xDist.add(Integer.parseInt(input[0]));
                    yDist.add(Integer.parseInt(input[1]));
                }

                Collections.sort(xDist);
                Collections.sort(yDist);

                if ((xDist.size() % 2) != 0) {
                    x = xDist.get(xDist.size() / 2);
                    y = yDist.get(yDist.size() / 2);
                }

                else {
                    x = xDist.get(xDist.size() / 2 - 1);
                    y = yDist.get(yDist.size() / 2 - 1);
                }
                
                out.write(Integer.toString(x) + " " + Integer.toString(y) + "\n");
                inp = in.readLine();
            }
            out.flush();
        } catch (Exception e) {e.printStackTrace();}

    }
}
