#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos, capacidadBarra, factor, tiempo;
    cin >> numCasos;
    while (numCasos--) {
        cin >> capacidadBarra >> factor >> tiempo;
        cout << (tiempo % (capacidadBarra + 1)) * factor << '\n';
    }
    return 0;
}