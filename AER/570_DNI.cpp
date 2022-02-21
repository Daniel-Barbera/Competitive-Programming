#include <bits/stdc++.h>
using namespace std;

int calcularPosibles(string dni) {
    int numIlegibles = 0;   // # de '?' en dni
    int ilegibles[4];   // Aquí se almacenan las posiciones de los '?'
    int posibles = 0;   // variable a retornar por la función
    char caracteres[] = {
        'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'
    };

    // Contar # de '?'
    for (int i = 0; i < 8; ++i) {
        if (dni[i] == '?') {
            ilegibles[numIlegibles] = i;
            ++numIlegibles;
        }
    }
    
    // Probar todas las combinaciones posibles en función del # de '?'
    string nif = dni.substr(0, 8);
    switch (numIlegibles) {
        case 1:
            for (int i = 0; i < 10; ++i) {
                nif[ilegibles[0]] = '0' + i;
                if (caracteres[stol(nif, nullptr, 10) % 23] == dni[8]) ++posibles;
            }
            break;
        case 2:
            for (int i = 0; i < 10; ++i) {
                nif[ilegibles[0]] = '0' + i;
                for (int j = 0; j < 10; ++j) {
                    nif[ilegibles[1]] = '0' + j;
                    if (caracteres[stol(nif, nullptr, 10) % 23] == dni[8]) ++posibles;
                }
            }
            break;
        case 3:
            for (int i = 0; i < 10; ++i) {
                nif[ilegibles[0]] = '0' + i;
                for (int j = 0; j < 10; ++j) {
                    nif[ilegibles[1]] = '0' + j;
                    for (int k = 0; k < 10; ++k) {
                        nif[ilegibles[2]] = '0' + k;
                        if (caracteres[stol(nif, nullptr, 10) % 23] == dni[8]) ++posibles;
                    }
                }
            }
            break;
        case 4: 
            for (int i = 0; i < 10; ++i) {
                nif[ilegibles[0]] = '0' + i;
                for (int j = 0; j < 10; ++j) {
                    nif[ilegibles[1]] = '0' + j;
                    for (int k = 0; k < 10; ++k) {
                        nif[ilegibles[2]] = '0' + k;
                        for (int l = 0; l < 10; ++l) {
                            nif[ilegibles[3]] == '0' + l;
                            if (caracteres[stol(nif, nullptr, 10) % 23] == dni[8]) ++posibles;
                        }
                    }
                }
            }
            break;
    }
    return posibles;
}
    
    
int main() {
    int numCasos;
    string dni;

    scanf("%d", &numCasos);
    while (numCasos--) {
        cin >> dni;
        printf("%d\n", calcularPosibles(dni));
    }
    return 0;
}