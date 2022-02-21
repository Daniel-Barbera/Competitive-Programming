#include <bits/stdc++.h>
using namespace std;

int calcValoresPosibles(int monedas[10], set<int>& valoresPosibles) {
    
}

int main() {
    int numCasos;
    int numMonedas;
    int maxMonedas;
    int monedas[10];
    cin >> numCasos;
    set<int> valoresPosibles;
    while (numCasos--) {
        cin >> numMonedas;
        cin >> maxMonedas;
        for (int i = 0; i < numMonedas; ++i) cin >> monedas[i];

        cout << valoresPosibles.size() << '\n';
    }
    return 0;
}