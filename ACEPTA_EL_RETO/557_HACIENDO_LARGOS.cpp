#include <bits/stdc++.h>
using namespace std;

int main() {

    int numCasos;
    long long int numLargos, tiempoLargo, largosSerie, descanso, tiempoExtra;
    long long int series;
    scanf ("%d", &numCasos);
    while (numCasos--) {
        scanf("%lld %lld %lld %lld %lld", &numLargos, &tiempoLargo, &largosSerie, &descanso, &tiempoExtra);

        series = numLargos / largosSerie + 1*(numLargos % largosSerie != 0) - 1; // -1 porque despues de la última serie no se descansa
        printf("%lld\n", (series*(descanso + (descanso + tiempoExtra*(series-1))))/2 + numLargos*tiempoLargo);
    }
}