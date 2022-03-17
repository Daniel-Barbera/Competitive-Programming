#include <bits/stdc++.h>
#define MAXN 10010
#define ll long long
using namespace std;

struct edge {
    int from, to, weight;
    edge(int f, int t, int w) {
        from = f;
        to = t;
        weight = w;
    }
    edge() {}
    bool operator<(edge other) const {
        return other.weight < weight;
    }
};

struct state {
    int node, dist;
    state() {};
    state(int n, int d) {
        node = n;
        dist = d;
    }
    bool operator< (state other) const {
        return other.dist < dist;
    }
};

constexpr int INF = 0x3f3f3f;
int n, e, maxWht, dest; 
array<int, MAXN> dist;
unordered_map<int, vector<edge>> graph;

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<state> pq;
    pq.push(state(start, 0));
    while(!pq.empty()){
        state cur = pq.top(); pq.pop();
        if(dist[cur.node] < cur.dist) continue;
        for(int i=0;i<graph[cur.node].size();i++){
            int dest = graph[cur.node][i].to;
            int wht = graph[cur.node][i].weight + cur.dist;
            if(dist[dest] <= wht) continue;
            dist[dest] = wht;
            pq.push(state(dest, wht));
        }
  }
}

int main() {
    int f, t, w;
    while (scanf("%d %d %d %d", &n, &dest, &maxWht, &e) == 4) {
        for (int i = 1; i <= n; ++i) dist[i] = INF;
        while (e--) {
            scanf("%d %d %d", &t, &f, &w);
            graph[f].push_back({f, t, w}); 
        }
        dijkstra(dest);
        int resultado = 0; 
        for (int i = 1; i <= n; ++i) {
            if (dist[i] <= maxWht && i != dest) ++resultado;
        }
        printf("%d\n", resultado);
        graph.clear();
    }
    return 0;
}