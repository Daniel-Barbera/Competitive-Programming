#include <bits/stdc++.h>
using namespace std;

int main() {
    
    constexpr int maxTiempo = 14*60;
    int numCasos;
    scanf("%d", &numCasos);
    int duracionPartida, numClases;
    int horas, minutos, duracion, horaAnterior, horaSiguiente = 0;
    int tiempoJugando, tiempoLibre;

    while (numCasos--) {
        scanf("%d %d", &duracionPartida, &numClases);

        horaAnterior = 480;
        tiempoJugando = 0;
        while (numClases--) {
            scanf("%d:%d %d", &horas, &minutos, &duracion);

            horaSiguiente = horas*60 + minutos;
            tiempoLibre = horaSiguiente - horaAnterior;
            if (tiempoLibre >= duracionPartida) tiempoJugando +=tiempoLibre;
            horaAnterior = horaSiguiente + duracion;
        }

        tiempoLibre = maxTiempo - horaAnterior;
        if (tiempoLibre / duracionPartida > 0) tiempoJugando += tiempoLibre;
        
        printf("%d\n", tiempoJugando);
    }
    return 0;
}
/*
2
30 3
08:30 60 // 08:00 - 08:30 - Tiene 30 mins
09:30 60 // 09:30 - 10:30 - No tiene tiempo
10:30 95 // 10:30 - 12:05 - No tiene tiempo
         // 12:05 - 14:00 - Tiene 115 mins
*/
