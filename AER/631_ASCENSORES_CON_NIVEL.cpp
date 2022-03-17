#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 100010
using namespace std;

struct edge {
    int destination, weight;
    edge() {};
    edge(int d, int w) {
        destination = d;
        weight = w;
    }
};

array<vector<edge>, MAXN> graph;
bitset<MAXN> visited = {0};

int minMaxEdge(int current, int top) {
    
}

int main() {
    int numEdges, f, t, w;
    int top;
    while (cin >> numEdges) {
        top = 0; 
        for (int i = 0; i < numEdges; ++i) {
            cin >> f >> t >> w;
            top = max(top, t);
            for (int i = f + 1; i <= t; ++i) graph[f].push_back({i, w});
        }
        cout << minMaxEdge(0, top) << '\n';
        for (int i = 0; i < numEdges; ++i) {
            visited[i] = false;
            graph[i].clear();
        }
    }
    return 0;
}