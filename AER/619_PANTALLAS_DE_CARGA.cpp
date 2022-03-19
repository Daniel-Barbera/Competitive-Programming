#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ancho, alto, alturaBloque, anchoBloque;  
    char color; 
    set<char> colores; 
    while (cin >> ancho >> alto && (ancho || alto)) {
        cin.ignore();
        alturaBloque = alto / 8;
        anchoBloque = ancho / 8;
        string bloques[alturaBloque][anchoBloque];

        for (int i = 0; i < alto; ++i) {
            for (int j = 0; j < ancho; ++j) {
                cin >> color;
                bloques[i/8][j/8] += color;
            }
            cin.ignore();
        }
        
        bool sePuede = true; 
        for (int i = 0; i < alturaBloque && sePuede; ++i) {
            for (int j = 0; j < anchoBloque && sePuede; ++j) {
                for (char c: bloques[i][j]) {
                    colores.insert(c);
                    sePuede = colores.size() < 3; 
                    if (!sePuede) break; 
                }
                colores.clear();
            }
        }
        sePuede ? cout << "SI\n" : cout << "NO\n";
    }
    return 0; 
}