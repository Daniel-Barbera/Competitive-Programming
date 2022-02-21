#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int numDias = 1;
    array<int, 1005> lis;
    array<unsigned long long int, 1005> dias;
    int maximo;
    int resultado;
    while (cin >> numDias && numDias != 0) {
        resultado = 0;
        lis.fill(0);
        for (int i = 0; i < numDias; ++i) {
            cin >> dias[i];
        }
        for (int i = 0; i < numDias; ++i) {
            maximo = 0;
            for (int j = 0; j <= i; ++j) {
                if (dias[j] < dias[i]) {
                    maximo = max(lis[j], maximo);
                }
            }
            lis[i] = maximo + 1;
            resultado = max(lis[i], resultado);
        }
        cout << resultado << "\n";
    }
}