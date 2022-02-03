#include <iostream>
using namespace std;

int main() {
    int numMuestras = 1;
    int indicador;
    int aux;
    bool crisis;
    while (numMuestras != 0) {
        cin >> numMuestras;
        if (numMuestras == 0) return 0;
        aux = 0;
        crisis = false;
        for (int i = 0; i < numMuestras; ++i) {
            cin >> indicador;
            if (indicador <= aux) {
                crisis = true;
                for (int j = i + 1; j < numMuestras; ++j) {
                    cin >> indicador;
                }
                break;
            } else {
                aux = indicador;
            }
        }
        if (!crisis) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}