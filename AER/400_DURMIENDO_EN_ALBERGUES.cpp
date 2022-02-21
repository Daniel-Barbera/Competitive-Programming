#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string entrada;
    int distancia;
    int mejorDistancia;
    int respuesta;
    while (cin >> entrada) {
        distancia = 0;
        mejorDistancia = -0x3f3f3f;
        for (auto it: entrada) {
            if (it == '.') ++distancia;
            if (it == 'X') {
                mejorDistancia = max(distancia, mejorDistancia);
                distancia = 0;
            }
        }
    }
    return 0;
}