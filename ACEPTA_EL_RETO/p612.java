import java.io.*;
public class p612 {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        try {
            String inp = in.readLine();
            while (inp != null) {
                String[] input = inp.split(" ");

                long radio = Long.parseLong(input[0]);
                Punto pt = new Punto(Long.parseLong(input[1]), Long.parseLong(input[2]));
                System.out.println(drawCircles(new Circulo(new Punto(0, 0), radio), pt));

                inp = in.readLine();
            }
        } catch (Exception e) {e.printStackTrace();}
    }

    public static int drawCircles(Circulo circulo, Punto target) {
        if (circulo.radio == 1) {
            if (circulo.hasPoint(target)) return 1;
            else return 0;
        }

        Punto centro = circulo.centro; // Para evitar escribir circulo.centro.x blablabla
        long radio = circulo.radio;
        Punto rPoint = new Punto(centro.x + radio, centro.y), lPoint = new Punto(centro.x - radio, centro.y),
              uPoint = new Punto(centro.x, centro.y + radio), dPoint = new Punto(centro.x, centro.y - radio);
        
        radio = radio / 2; 
        int hasPoint = circulo.hasPoint(target) ? 1 : 0;
        Punto closestToTarget = target.chooseClosest(rPoint, lPoint, uPoint, dPoint);  
        return hasPoint + drawCircles(new Circulo(closestToTarget, radio), target);
    }

    public static class Circulo {
        public Punto centro;
        public long radio;
        public Circulo(Punto centro, long radio) {
            this.centro = centro; 
            this.radio = radio;
        }
                
        public boolean hasPoint(Punto pt) {
            /* (x - c_x)^2 + (y - c_y)^2 <= r^2 */
            return (
                (pt.x*pt.x - 2*pt.x*centro.x + centro.x*centro.x) +
                (pt.y*pt.y - 2*pt.y*centro.y + centro.y*centro.y) <=
                (radio*radio)
            );
        }
    }

    public static class Punto {
        public long x, y;
        public Punto(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public Punto chooseClosest(Punto rp, Punto lp, Punto up, Punto dp) {
            long rDistance = distanceTo(rp), lDistance = distanceTo(lp),
                   uDistance = distanceTo(up), dDistance = distanceTo(dp);

            long closest = Math.min(rDistance, Math.min(lDistance, Math.min(uDistance, dDistance)));
            if (closest == rDistance) return rp;
            if (closest == lDistance) return lp;
            if (closest == uDistance) return up;
            return dp;
        }

        public long distanceTo(Punto pt) {
            return (
                (pt.x*pt.x - 2*pt.x*x + x*x) + (pt.y*pt.y - 2*pt.y*y + y*y)
            );
        }
    }
}
