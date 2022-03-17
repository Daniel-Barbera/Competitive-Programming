import java.util.*;
import java.io.*; 

public class p318 {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); 
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out)); 
        int[] wht = new int[1005];
        int[] dist = new int[1005];
        HashMap<Integer, ArrayList<IntPair>> graph = new HashMap<>();

        String input;
        String[] inputArr; 
        try {
            while ((input = in.readLine()) != null) {
                int n = Integer.parseInt(input); 

                inputArr = in.readLine().split(" "); 
                for (int i = 1; i <= n; ++i) {
                    wht[i] = Integer.parseInt(inputArr[i-1]);
                    graph.put(i, new ArrayList<IntPair>()); 
                }

                int e = Integer.parseInt(in.readLine());
                int f, t, w;
                for (int i = 0; i < e; ++i) {
                    inputArr = in.readLine().split(" "); 
                    f = Integer.parseInt(inputArr[0]); t = Integer.parseInt((inputArr[1])); w = Integer.parseInt(inputArr[2]) + wht[f];
                    graph.get(f).add(new IntPair(t, w));
                }

                int result = dijkstra(graph, dist, n);
                if (result != -1) out.write(Integer.toString(result + wht[n]) + "\n");
                else out.write("IMPOSIBLE\n");
                graph.clear();
            }
            out.flush();
        }
        catch (Exception ee) {}

    }

    public static int dijkstra(HashMap<Integer, ArrayList<IntPair>> graph, int[] dist, int end) {
        for (int i = 0; i <= end; ++i) dist[i] = Integer.MAX_VALUE;

        PriorityQueue<IntPair> pq = new PriorityQueue<>();
        pq.offer(new IntPair(1, 0)); //offer==add
        dist[1]=0;

        while(!pq.isEmpty()){
            IntPair cur = pq.poll(); //poll==remove
            if (dist[cur.node] < cur.dist) continue;
            if (cur.node == end) return cur.dist;

            ArrayList<IntPair> adj = graph.get(cur.node);
            for (IntPair edge: adj) {
                int dest = edge.node; 
                int wht = edge.dist + cur.dist;
                if (dist[dest] <= wht) continue; 
                dist[dest] = wht;
                pq.offer(new IntPair(dest, wht)); 
            }
        }
        return -1;
    }

    public static class IntPair implements Comparable {
        public int node;
        public int dist;
        public IntPair(int node, int dist){
            this.node = node;
            this.dist = dist;
        }
        @Override
        public int compareTo(Object o) {
            IntPair k= (IntPair) o;
            if(k.dist==this.dist){
                return(this.node-k.node);
            }else{
                return(this.dist-k.dist);
            }
        }
    }


}