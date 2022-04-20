import java.io.*;
public class p612 {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        try {
            String inp = in.readLine();
            while (inp != null) {
                String[] input = inp.split(" ");

                long radio = Long.parseLong(input[0]);
                Point pt = new Point(Long.parseLong(input[1]), Long.parseLong(input[2]));
                System.out.println(drawCircles(new Circle(new Point(0, 0), radio), pt));

                inp = in.readLine();
            }
        } catch (Exception e) {e.printStackTrace();}
    }

    public static int drawCircles(Circle Circle, Point target) {
        if (Circle.radio == 1) {
            if (Circle.hasPoint(target)) return 1;
            else return 0;
        }

        Point center = Circle.center; // Para evitar escribir Circle.center.x blablabla
        long radio = Circle.radio;
        Point rPoint = new Point(center.x + radio, center.y), lPoint = new Point(center.x - radio, center.y),
              uPoint = new Point(center.x, center.y + radio), dPoint = new Point(center.x, center.y - radio);
        
        radio = radio / 2; 
        int hasPoint = Circle.hasPoint(target) ? 1 : 0;
        Point closestToTarget = target.chooseClosest(rPoint, lPoint, uPoint, dPoint);  
        return hasPoint + drawCircles(new Circle(closestToTarget, radio), target);
    }

    public static class Circle {
        public Point center;
        public long radio;
        public Circle(Point center, long radio) {
            this.center = center; 
            this.radio = radio;
        }
                
        public boolean hasPoint(Point pt) {
            /* (x - c_x)^2 + (y - c_y)^2 <= r^2 */
            return (
                (pt.x*pt.x - 2*pt.x*center.x + center.x*center.x) +
                (pt.y*pt.y - 2*pt.y*center.y + center.y*center.y) <=
                (radio*radio)
            );
        }
    }

    public static class Point {
        public long x, y;
        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public Point chooseClosest(Point rp, Point lp, Point up, Point dp) {
            long rDistance = distanceTo(rp), lDistance = distanceTo(lp),
                   uDistance = distanceTo(up), dDistance = distanceTo(dp);

            long closest = Math.min(rDistance, Math.min(lDistance, Math.min(uDistance, dDistance)));
            if (closest == rDistance) return rp;
            if (closest == lDistance) return lp;
            if (closest == uDistance) return up;
            return dp;
        }

        public long distanceTo(Point pt) {
            return (
                (pt.x*pt.x - 2*pt.x*x + x*x) + (pt.y*pt.y - 2*pt.y*y + y*y)
            );
        }
    }
}
