#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos, capacidad, numCompartimentos, diferencia;
    int resultado;
    cin >> numCasos;
    while (numCasos--) {
        cin >> numCompartimentos >> capacidad >> diferencia;
        resultado = capacidad;
        --numCompartimentos;
        while (numCompartimentos--) {
            capacidad = capacidad - diferencia;
            resultado += capacidad; 
        }
        cout << resultado << '\n';
    }
    return 0;
}