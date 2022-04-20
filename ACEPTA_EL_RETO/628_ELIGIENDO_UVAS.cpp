#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int sabor, grosor;
    pair<long long int, long long int> mejorUva; 
    long long int mejorSabor = numeric_limits<long long int>::min();
    long long int mejorGrosor = numeric_limits<long long int>::max();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> sabor >> grosor) {
        if (sabor == 0 || grosor == 0) {
            // Se entiende que la solución es única si no existen dos uvas distintas con valores iguales
            if (mejorUva.first != mejorSabor || mejorUva.second != mejorGrosor)cout << "NO HAY MEJOR" << '\n';
            else cout << mejorUva.first << ' ' << mejorUva.second << '\n';
            mejorSabor = numeric_limits<long long int>::min();
            mejorGrosor = numeric_limits<long long int>::max();
        } else {
            if (sabor >= mejorSabor && grosor <= mejorGrosor) {
                mejorUva.first = sabor;
                mejorUva.second = grosor;
            }
            mejorSabor = max(sabor, mejorSabor);
            mejorGrosor = min(grosor, mejorGrosor);
        }
    }
    return 0;
}