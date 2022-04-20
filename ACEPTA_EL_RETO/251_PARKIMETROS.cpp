#include <bits/stdc++.h>
#define TAM_ARRAY sizeof(sol)/sizeof(int)
using namespace std;


int monedas[10] = {};
int numMonedas, maxMonedas;
bool visited[2050];

/* Idea del BFS:
    Evitar recorrer el árbol de expansión sin podar, explorando solo el árbol compuesto
    por los nodos que son solución. En este caso, cada nodo es una suma.
    La cola de nodos a visitar está compuesta por el par (suma, cantidadMonedas)
    Donde:
        - CantidadMonedas controla que para una rama explorada, no hayamos
        encolado más de maxMonedas monedas (imposible)
        - Suma almacena el nodo en el que estamos, al que se le sumarán monedas para
        alcanzar el siguiente nodo.
    De esta forma, se evita encolar cualquier nodo que haya sido visitado antes.
*/

long long int bfs() {
    pair<int, int> nodo;
    queue<pair<int, int>> cola;
    cola.push(make_pair(0,0));
    long long int resultado = 0;

    while (!cola.empty()) {
        nodo = cola.front(); cola.pop();

        for (int i = 0; i < numMonedas; ++i) {
            if (!visited[nodo.first+monedas[i]] && nodo.second < maxMonedas) {
                visited[nodo.first+monedas[i]] = true;
                cola.push(make_pair(nodo.first + monedas[i], nodo.second + 1));
                ++resultado;
            }   
        }
    }
    return resultado;
}

int main() {
    int numCasos;
    cin >> numCasos;
    while (numCasos--) {
        cin >> numMonedas >> maxMonedas;
        for (int i = 0; i < numMonedas; ++i) {
            cin >> monedas[i];
        }
        memset(visited, 0, sizeof(visited));
        cout << bfs() << '\n';
        for (int i = 0; i < numMonedas; ++i) monedas[i] = 0;
    }
}