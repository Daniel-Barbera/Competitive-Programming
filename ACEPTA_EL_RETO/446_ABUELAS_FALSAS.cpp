#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int numCasos;
    int numNombres;
    string nombreNieto; 
    string nombreLeido;
    cin >> numCasos;
    bool esAbuela = true;
    for (int j = 0; j < numCasos; ++j) {
        cin >> nombreNieto;
        cin >> numNombres;
        esAbuela = true;
        for (int i = 0; i < numNombres - 1; ++i) {
            cin >> nombreLeido;
            if (nombreLeido == nombreNieto) esAbuela = false;
        }
        cin >> nombreLeido;
        if (esAbuela) esAbuela = nombreNieto == nombreLeido;
        if (esAbuela && numNombres > 1) cout << "VERDADERA\n";
        else cout << "FALSA\n";
    }
    return 0;
}