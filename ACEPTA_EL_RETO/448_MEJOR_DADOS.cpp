#include <bits/stdc++.h>
using namespace std;

int caras[100005];
int numMayoresQuePrimero;
int caraSegundoDado;
int iguales;
int main() {
    int numCaras = 1;
    while (scanf("%d", &numCaras) && numCaras != 0) {
        numMayoresQuePrimero = 0;
        iguales = 0;
        for (int i = 0; i < numCaras; ++i) {
            scanf("%d", &caras[i]);
        }
        for (int j = 0; j < numCaras; ++j) {
            scanf("%d", &caraSegundoDado);
            if (caraSegundoDado > caras[j]) ++numMayoresQuePrimero;
            if (caraSegundoDado == caras[j]) ++iguales;
        }
        if (iguales == numCaras) {
            printf("NO HAY DIFERENCIA\n");
            continue;
        }
        if (numMayoresQuePrimero > numCaras/2) printf("SEGUNDO\n");
        else if (numMayoresQuePrimero < numCaras/2) printf("PRIMERO\n");
    }
    return 0;
}