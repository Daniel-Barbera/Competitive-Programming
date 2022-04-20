import java.io.*;
import java.util.*;

public class p631 {
    public static final int MAXN = 1000001; 
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Integer, ArrayList<IntPair>> graph = new HashMap<>();
        ArrayList<Integer> dist = new ArrayList<>(MAXN);
        try {
            int f, t, w, top = 0;
            String s;
            while ((s = in.readLine()) != null) {
                int e = Integer.parseInt(s);
                
                ArrayList<String> intervalos = new ArrayList<>();
                for (int i = 0; i < e; ++i) {
                    intervalos.add(in.readLine());
                }

                for (int i = 0; i < e; ++i) {
                    String[] interv = intervalos.get(i).split(" ");
                    f = Integer.parseInt(interv[0]); t = Integer.parseInt(interv[1]); w = Integer.parseInt(interv[2]);
                    top = (top > t) ? top : t;
                    IntPair edge = new IntPair(t, w), backw = new IntPair(f, w); 

                    ArrayList<IntPair> edges = graph.get(f), wtf = graph.get(t);
                    if (edges == null) edges = new ArrayList<IntPair>();
                    if (wtf == null) wtf = new ArrayList<IntPair>();
                    edges.add(edge);
                    wtf.add(backw);
                    graph.put(f, edges);
                    graph.put(t, wtf);
                    
                    for (int j = f + 1; j < t; ++j) {
                        ArrayList<IntPair> aux = graph.get(j);
                        if (aux != null) {
                            aux.add(edge);
                            graph.put(j, aux);
                        }
                    }
                }

                System.out.println(minMaxEdge(graph, top, dist));
                for (Integer key : graph.keySet()) {
                    graph.put(key, null);
                }
            }
        } catch (Exception e) {e.printStackTrace();}
    }

    public static int minMaxEdge(HashMap<Integer, ArrayList<IntPair>> graph, int top, ArrayList<Integer> dist) {
        for (int i = 0; i <= top; ++i) dist.add(Integer.MAX_VALUE);
        dist.set(0, 0);

        PriorityQueue<IntPair> pq = new PriorityQueue<>();
        pq.offer(new IntPair(0, 0)); 

        while (!pq.isEmpty()) {
            IntPair p = pq.poll();
            int pri = p.node, u = p.distance;
            if (-pri > dist.get(u)) {
                continue;
            }
            for (IntPair o : graph.get(u)) {
                int v = o.node, w = o.distance; 
                if (u == 0 && v == top) {
                    continue;
                }
                if (dist.get(v) > Math.max(dist.get(u), w)) {
                    dist.set(v, Math.max(dist.get(u), w));
                    pq.offer(new IntPair(-dist.get(v), v));
                }
            }
        }
        return dist.get(top);
    }

    public static class IntPair implements Comparable {
        public int node; 
        public int distance;

        public IntPair(int n, int d) {
            this.node = n;
            this.distance = d; 
        }

        @Override
        public int compareTo(Object o) {
            IntPair other = (IntPair) o; 
            if (this.distance == other.distance) {
                return this.node - other.node;
            }
            return this.distance - other.distance; 
        }
    }
}
