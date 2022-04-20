import java.util.*;
import java.io.*;

public class p632 {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        LinkedList<Integer> fRow = new LinkedList<>(), sRow = new LinkedList<>();

        while (in.hasNextInt()) {
            int fLength = in.nextInt(), sLength = in.nextInt(), time = in.nextInt(), result = 0;

            for (int i = 0; i < fLength; ++i) fRow.add(in.nextInt());
            for (int i = 0; i < sLength; ++i) sRow.add(in.nextInt());
            
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            int f = -1, s = -1, top;
            
            if (!fRow.isEmpty()) pq.offer(f = fRow.removeLast());
            if (!sRow.isEmpty()) pq.offer(s = sRow.removeLast());
            while (time >= 0 && !pq.isEmpty() && pq.peek() <= time) {
                top = pq.poll();
                time -= top;
                ++result;
                if (top == f) {
                    if (!fRow.isEmpty()) pq.offer(f = fRow.removeLast());
                    else if (!sRow.isEmpty()) pq.offer(s = sRow.removeLast());
                } else {
                    if (!sRow.isEmpty()) pq.offer(s = sRow.removeLast());
                    else if (!fRow.isEmpty()) pq.offer(f = fRow.removeLast());
                }
            }

            System.out.println(result);
            fRow.clear(); sRow.clear();
        }
    }
    
}

