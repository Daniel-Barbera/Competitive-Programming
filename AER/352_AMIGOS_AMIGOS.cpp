#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
#include <map>
using namespace std;

int bfs(map<int, vector<int>>& grafo, array<bool, 20050>& visited, int numPersonas, int nodo);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, vector<int>> grafo;
    array<bool, 20050> visited = {};
    int numCasos, numPersonas, numAmigos; // c, V, E
    int a, b, resultado;

    cin >> numCasos;
    while (numCasos--) {
        visited[0] = true;
        cin >> numPersonas >> numAmigos;
        for (int i = 0; i < numAmigos; ++i) {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        int posNext = -1;
        resultado = -1;
        while (posNext != 0) {
            posNext = 0;
            for (int i = 1; i <= numPersonas; ++i) {
                if (visited[i] == false) {
                    posNext = i;
                    break;
                }
            }
            if (posNext) resultado = max(resultado, bfs(grafo, visited, numPersonas, posNext));
        }
        cout << resultado << '\n';
        visited.fill(0);
        grafo.clear();
    }
}

int bfs(map<int, vector<int>>& grafo, array<bool, 20050>& visited, int numPersonas, int nodo) {
    int resultado = 0;
    queue<int> cola;
    cola.push(nodo);
    while (!cola.empty()) {
        nodo = cola.front(); cola.pop();
        visited[nodo] = true;
        for (auto it : grafo[nodo]) {
            if (!visited[it]) {
                cola.push(it);
                visited[it] = true;
            }
        }
        ++resultado;
    }
    return resultado;
}