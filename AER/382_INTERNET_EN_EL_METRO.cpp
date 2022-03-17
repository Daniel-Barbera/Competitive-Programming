#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /* NO!!! Buscar algoritmo */


    int numCasos = 1;
    int longTunel, numAntenas;
    int segmentoCubierto;
    int distancia, cobertura;
    cin >> numCasos;
    while (numCasos--) {
        cin >> longTunel >> numAntenas;
        segmentoCubierto = 0;
        while (numAntenas--) {
            cin >> distancia >> cobertura;
            if (distancia >= segmentoCubierto) segmentoCubierto += (distancia - segmentoCubierto) + cobertura;
            else segmentoCubierto += max(0, (segmentoCubierto - distancia + cobertura));
        }
        segmentoCubierto >= longTunel ? cout << "SI\n" : cout << "NO\n";
    }
}
4
1500 2
500 500 1000 500
50 2
10 10 40 10
50 3
10 5 30 5 30 25
100 3
30 30 70 5 75 25