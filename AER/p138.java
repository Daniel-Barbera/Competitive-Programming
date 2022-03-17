import java.io.*;


public class p138 {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        try {
            int n = Integer.parseInt(in.readLine());

            int num; int ceros;
            for (int i = 0; i < n; ++i) {
                ceros = 0;
                num = Integer.parseInt(in.readLine());
                while (num != 0) {
                    ceros += num / 5;
                    num = num / 5; 
                }
                out.write(Integer.toString(ceros) + "\n");
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace(); 
        }
        
    }
}
