#include <bits/stdc++.h>
using namespace std;

int main() {

    int numExamenes = 1;	// # casos
    int notasExamen[10];	
    int mediaNecesaria;
    int notaActual;		// sumatorio notas actuales
    int notaRequerida;		// output

    while (scanf("%d", &numExamenes) && numExamenes != 0) {
        notaActual = 0.0;
        notaRequerida = 0;
        for(int i = 0; i < numExamenes; ++i) {
            scanf("%d", &notasExamen[i]);
            notaActual += notasExamen[i];
        }
        scanf("%d", &mediaNecesaria);
        numExamenes = numExamenes + 1;  // la cantidad de exámenes a considerar en la media
        notaRequerida = numExamenes*mediaNecesaria - notaActual;	// <- solve (notaActual / n + notaRequerida / n = mediaNecesaria)
        if (notaRequerida > 10 || notaRequerida < 0) printf("IMPOSIBLE\n");
        else printf("%d\n", notaRequerida);
    }
    return 0;
}