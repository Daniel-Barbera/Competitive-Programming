#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int numCasos;
    int numPaginas;
    int diferencia, auxDiferencia;
    int mayor;
    int menor;
    int num = 0;
    int numAnterior;
    cin >> numCasos;
    
    while (numCasos--) {
        cin >> numPaginas;

        cin >> num;
        mayor = num;
        numAnterior = num;
        diferencia = -999999;
        --numPaginas;
        while (numPaginas--) {
            cin >> num;
            auxDiferencia = mayor - num;
            diferencia = auxDiferencia > diferencia ? auxDiferencia : diferencia;
            numAnterior = num;
            mayor = mayor > num ? mayor : num;
        }
        cout << diferencia << "\n";
    }   
}