#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string entrada;
    string mensaje;
    char aux;
    int i;
    while (getline(cin, entrada)) {
        i = 0;
        while (i < entrada.length()) {
            aux = stoi(entrada.substr(i, 2));
            if (!isalpha(aux) && aux != ' ' && !ispunct(aux)) {
                aux = stoi(entrada.substr(i, 3));
                i += 3;
            } else i += 2;
            mensaje += aux;
        }
        cout << mensaje << '\n';
        mensaje.clear();
    }
}