#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 21> equipos = {0};
    int numEquipos, numGlobos; 
    numEquipos = numGlobos = 0;
    int id, ganador;
    int* max;
    bool empate;
    string trash;

    while (cin >> numEquipos >> numGlobos && numEquipos) {
        while (numGlobos--) {
            cin >> id >> trash;
            ++equipos[id];
        }
        max = max_element(equipos.begin()+1, equipos.begin() + numEquipos + 1);
        // Sacar el id del elemento mayor
        for (int i = 1; i <= numEquipos; ++i) {
            if (equipos[i] == *max) {
                ganador = i;
                break;
            }
        }
        // Equivalente a contar con un bucle for
        empate = count_if(equipos.begin() + 1, equipos.begin() + numEquipos + 1, [&max](int num){return num == *max;}) > 1;
        empate ? cout << "EMPATE\n" : cout << ganador << '\n';
        // Limpiar array
        for (int i = 1; i <= numEquipos; ++i) equipos[i] = 0;
    }
    return 0;
}