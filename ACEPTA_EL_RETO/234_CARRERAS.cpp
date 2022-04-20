#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int numCasos, numPilas;
    int voltajeMin, voltajePila;
    int resultado;
    int pilas[100005];

    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resultado = 0;
        cin >> numPilas;
        cin >> voltajeMin;

        for (int j = 0; j < numPilas; ++j) {
            cin >> voltajePila;
            pilas[j] = voltajePila;
        }

        sort(pilas, pilas + numPilas, greater<int>());

        int k = numPilas - 1;
        int l = 0;

        while (l < k) {
            if (pilas[l] + pilas[k] >= voltajeMin) {
                ++l;
                --k;
                ++resultado;
            } else {
                --k;
            }
        }
        cout << resultado << endl;
    }

    return 0;
}