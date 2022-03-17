import java.io.*;
public class p604 {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        try{
            int numCasos = Integer.parseInt(in.readLine());
            while (numCasos-- != 0) {
                String[] mano = in.readLine().split(" ");
                int corazones, diamantes, picas, treboles;
                int honor, distribucion;
                corazones = diamantes = picas = treboles = honor = distribucion = 0;
                for (int i = 0; i < mano.length; i += 2) {
                    switch(mano[i]) {
                        case "A":
                            honor += 4;
                            break;
                        case "K":
                            honor += 3;
                            break;
                        case "Q":
                            honor += 2;
                            break;
                        case "J":
                            honor += 1;
                            break; 
                    }
                    switch(mano[i+1]) {
                        case "C":
                            ++corazones;
                            break;
                        case "D":
                            ++diamantes;
                            break;
                        case "P":
                            ++picas;
                            break;
                        case "T":
                            ++treboles;
                            break;
                    }
                }
                switch(corazones) {
                    case 2:
                        distribucion += 1;
                        break;
                    case 1:
                        distribucion += 2;
                        break;
                    case 0:
                        distribucion += 3;
                        break; 
                }
                switch(diamantes) {
                    case 2:
                        distribucion += 1;
                        break;
                    case 1:
                        distribucion += 2;
                        break;
                    case 0:
                        distribucion += 3;
                        break; 
                }
                switch(picas) {
                    case 2:
                        distribucion += 1;
                        break;
                    case 1:
                        distribucion += 2;
                        break;
                    case 0:
                        distribucion += 3;
                        break; 
                }
                switch(treboles) {
                    case 2:
                        distribucion += 1;
                        break;
                    case 1:
                        distribucion += 2;
                        break;
                    case 0:
                        distribucion += 3;
                        break; 
                }
                out.write(Integer.toString(honor + distribucion) + "\n");
            }
            out.flush();
        } catch (Exception e) {e.printStackTrace();}
    }
}
