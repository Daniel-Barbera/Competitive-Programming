#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double input;
    double media;
    pair<string, double> diaMinimo, diaMaximo;
    bool masVentasEnDomingo;
    string dias[6] = {"MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};
    while (true) {
        media = 0;
        diaMaximo.second = -0x3f3f3f;
        diaMinimo.second = 0x3f3f3f;
        for (int i = 0; i < 6; ++i) {
            cin >> input;
            if (input == -1) return 0;
            media += input;
            if (input < diaMinimo.second) diaMinimo = make_pair(dias[i], input);
            if (input > diaMaximo.second) diaMaximo = make_pair(dias[i], input);
        }
        media /= 6;
        masVentasEnDomingo = input > media;
        cout << diaMaximo.first << ' ' << diaMinimo.first << ' ';
        masVentasEnDomingo ? cout << "SI\n" : cout << "NO\n";
    }
}