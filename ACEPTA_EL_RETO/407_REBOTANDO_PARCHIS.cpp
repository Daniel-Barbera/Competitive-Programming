#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int casillas, pos, tirada, resultado;
    while (scanf("%d%d%d", &casillas, &pos, &tirada) == 3 && casillas && pos && tirada) {
        if (pos + tirada <= casillas) printf("%d\n", pos + tirada);
        else {
            tirada -= casillas - pos;
            resultado = casillas - tirada;
            printf("%d\n", resultado);
        }
    }

    return 0; 
}