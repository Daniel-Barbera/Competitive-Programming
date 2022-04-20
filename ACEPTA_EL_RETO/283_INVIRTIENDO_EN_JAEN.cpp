#include <bits/stdc++.h>
using namespace std;

int bfs(array<array<bool, 105>, 105>& grafo, array<array<bool, 105>, 105>& visited, int numF, int numC, int i, int j) {
    queue<pair<int, int>> cola;
    pair<int, int> node;
    int resultado = 0;
    
    cola.push(make_pair(i, j));
    while (!cola.empty()) {
        node = cola.front(); cola.pop();
        visited[node.first][node.second] = true;
        //Izquierda
        if (node.first != 0) {
            if (!visited[node.first - 1][node.second]) {
                visited[node.first - 1][node.second] = true;
                cola.push(make_pair(node.first - 1, node.second));
            }
        }
        //Derecha
        if (node.first != numF - 1) {
            if (!visited[node.first + 1][node.second]) {
                visited[node.first + 1][node.second] = true;
                cola.push(make_pair(node.first + 1, node.second));
            }
        }//Arriba
        if (node.second != 0) {
            if (!visited[node.first][node.second - 1]) {
                visited[node.first][node.second - 1] = true;
                cola.push(make_pair(node.first, node.second - 1));
            }
        }//Abajo
        if (node.second != numC - 1) {
            if (!visited[node.first][node.second + 1]) {
                visited[node.first][node.second + 1] = true;
                cola.push(make_pair(node.first, node.second + 1));
            }
        }
        ++resultado;
    }
    return resultado;
}


int main() {
    int numFilas, numColumnas;
    array<array<bool, 105>, 105> visited = {false};
    array<array<bool, 105>, 105> grafo = {false};
    char c;
    int resultado;
    string entrada;
    while (cin >> numFilas >> numColumnas) {
        cin.ignore();
        // Leer grafo
        for (int i = 0; i < numFilas; ++i) {
            for (int j = 0; j < numColumnas; ++j) {
                cin.get(c);
                if (c == '#') grafo[i][j] = true;
                if (c == ' ') visited[i][j] = true;
            }
            cin.ignore();
        }
        // Quedarse con la componente conexa mayor
        resultado = 0;
        for (int i = 0; i < numFilas; ++i) {
            for (int j = 0; j < numColumnas; ++j)
                if (!visited[i][j]) resultado = max(resultado, bfs(grafo, visited, numFilas, numColumnas, i, j));
        }
        cout << resultado << '\n';
        //Limpiar visited
        for (int i = 0; i < numFilas; ++i) {
            for (int j = 0; j < numColumnas; ++j) {
                grafo[i][j] = false;
                visited[i][j] = false;
            }
        }
    }
    return 0;
}