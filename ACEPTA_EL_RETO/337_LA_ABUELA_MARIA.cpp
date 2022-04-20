#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numCasos;
    int superiores[6];
    int inferiores[6];
    int altura;
    bool noIguales;

    cin >> numCasos;
    while (numCasos--) {
        for (int i = 0; i < 6; ++i) cin >> superiores[i];
        for (int i = 0; i < 6; ++i) cin >> inferiores[i];
        altura = superiores[0] + inferiores[0];
        for (int i = 1; i < 6; ++i) {
            noIguales = (superiores[i] + inferiores[i]) != altura;
            if (noIguales) break;
        }
        noIguales ? cout << "NO\n" : cout << "SI\n";
    }
    return 0;
}