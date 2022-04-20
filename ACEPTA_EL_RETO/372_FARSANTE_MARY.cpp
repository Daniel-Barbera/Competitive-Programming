#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int i;
    int numCasos;
    string entrada;
    string salida;
    cin >> numCasos;
    bool esMayuscula[40];
    while (numCasos--) {
        cin >> entrada;
        transform(entrada.begin(), entrada.end(), esMayuscula, [](unsigned char c) {return (isupper(c));});
        i = 0;
        for (auto it = entrada.rbegin(); it != entrada.rend(); ++it) {
            if (esMayuscula[i]) salida += toupper(*it);
            else salida += tolower(*it);
            ++i;
        }
        cout << salida << '\n';
        salida.clear();
        fill(esMayuscula, esMayuscula + 40, false);
    }
}