#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#define MAXN 10050
#define INF 0x3f3f3f3f
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
unordered_map<int, vector<edge>> graph;
bool visited[MAXN] = { 0 };
int dist[MAXN] = { 0 };

int prim(int src);

int main() {
    int v, e;
    int f, t, w;
    while (cin >> v >> e) {
        for (int i = 0; i < e; ++i) {
            cin >> f >> t >> w;
            graph[f].push_back(edge(f, t, w));
            graph[t].push_back(edge(t, f, w));
        }
        for (int i = 0; i <= v; ++i) {
            dist[i] = INF;
            visited[i] = false;
        }
        int resultado = prim(1);
        for (int i = 1; i <= v; ++i) {
            if (!visited[i]) {
                resultado = -1;
                break;
            }
        }
        resultado == -1 ? cout << "Imposible\n" : cout << resultado << '\n';
        graph.clear();
    }
}

int prim(int src) {
    priority_queue<state> pq;
    int res, numVisited;
    res = numVisited = 0;

    pq.push(state(src, 0));
    dist[src] = 0;
    while (!pq.empty()) {
        state cur = pq.top(); pq.pop();
        if (visited[cur.node]) continue;
        if (dist[cur.node] < cur.dist) continue;
        visited[cur.node] = true;
        for (auto it : graph[cur.node]) {
            int dest = it.to;
            int wght = it.weight;
            if (visited[dest]) continue;
            pq.push(state(dest, wght));
            dist[dest] = wght;
        }
        res += cur.dist;
    }
    return res;
}