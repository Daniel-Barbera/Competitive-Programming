#include <map>
#include <queue>
#include <array>
#include <vector>
#include <iostream>
using namespace std;

bool bfs(map<int, vector<int>>& grafo, array<bool, 105>& visited, array<bool, 105>& colores, int node) {
    queue<int> cola;
    cola.push(node);
    colores[node] = true;
    while (!cola.empty()) {
        node = cola.front(); cola.pop();
        visited[node] = true;
        for (auto ady : grafo[node]) {
            if (!visited[ady]) {
                cola.push(node);
                visited[ady] = true;
                colores[ady] = !colores[node];
            }
            else if (colores[ady] == colores[node]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, vector<int>> grafo;
    array<bool, 105> visited = {};
    array<bool, 105> colores = {};
    int V, E;
    int a, b;

    while (cin >> V) {
        cin >> E;
        while (E--) {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        bool esBipartito = true;
        for (int i = 0; i < grafo.size() && esBipartito; ++i)
            if (!visited[i]) esBipartito = bfs(grafo, visited, colores, i);
        esBipartito ? cout << "SI\n" : cout << "NO\n";
        colores.fill(0);
        visited.fill(0);
        grafo.clear();
    }
}