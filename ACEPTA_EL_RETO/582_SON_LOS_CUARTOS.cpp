#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numCasos;
    string entrada;
    cin >> numCasos;
    cin.ignore();
    while (numCasos--) {
        getline(cin, entrada);
        if (entrada.length() < 3) cout << "MARISA NARANJO\n";
        else if (entrada.find("ding-dong") != string::npos) cout << "SALIDA NULA\n";
        else if (count(entrada.begin(), entrada.end(), ' ') < 11) cout << "TARDE\n";
        else cout << "CORRECTO\n";
    }
    return 0;
}