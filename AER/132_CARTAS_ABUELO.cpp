#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string entrada;
    vector<int> eqv;
    int contador;
    int longitudEntrada;
    int numIntervalos, i, j;
    numIntervalos = -1;

    while (getline(cin, entrada)) {
        contador = 0;
        longitudEntrada = entrada.length();
        eqv.resize(entrada.length());
        for (int k = 0; k < longitudEntrada - 1; ++k) {
            eqv[i] = contador;
            if (entrada[i] != entrada[i+1]) ++contador;
        }
        eqv[longitudEntrada - 1] = contador;
        cin >> numIntervalos;
        if (numIntervalos == 0) break;
        for (int aux = 0; aux < numIntervalos; ++aux) {
            cin >> i;
            cin >> j; 
            if (eqv[i] == eqv[j]) cout << "SI\n";
            else cout << "NO\n";
        }
        cout << "\n";
        cin.ignore();
    }
    return 0;
}