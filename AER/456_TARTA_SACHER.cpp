#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    int ancho, alto, necesario;
    int aux;
    cin >> numCasos;
    while (numCasos--) {
        cin >> ancho >> alto >> necesario;
        necesario % (ancho*alto) != 0 ? aux = necesario / (ancho*alto) + 1 : aux = necesario / (ancho*alto);
        cout << aux << '\n';
    }
    return 0;
}