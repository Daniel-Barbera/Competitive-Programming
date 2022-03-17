#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 1010
using namespace std;

struct edge {
    int from, to, weight;
    edge(int f, int t, int w){
        from = f;
        to = t;
        weight = w;
    }
    edge(){}
    bool operator< (edge other) const {
        return other.weight < weight;
    }
};

struct state {
    int node, dist;
    state(int n, int d) {
        node = n;
        dist = d;
    }
    state(){}
    bool operator< (state other) {
        return other.dist < dist;
    }
};
vector<edge> graph[MAXN];
bool visited[MAXN];
bool dist[MAXN];

int main() {
    int v, dest;    
}
