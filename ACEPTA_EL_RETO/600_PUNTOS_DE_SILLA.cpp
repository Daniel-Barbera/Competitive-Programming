#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);

    int numFilas, numColumnas;
    int matriz[301][301];
    while (scanf("%d %d", &numFilas, &numColumnas) && (numFilas && numColumnas)) {
        for (int i = 0; i < numFilas; ++i) {
            for (int j = 0; j < numColumnas; ++j) {
                scanf("%d", &matriz[i][j]);
            }
        }

        /* Los puntos de silla de una matriz son aquellos elementos de la matriz
        que cumplen que son menores o iguales que el resto de elementos de su fila
        y mayores o iguales que el resto de elementos de su columna,
         o al revés, mayores o iguales que el resto de elementos de su fila
        y menores o iguales que el resto de elementos de su columna. */

        bool noTiene, menorIgualFila, menorIgualColumna, mayorIgualFila, mayorIgualColumna;
        noTiene = true;
        for (int i = 0; i < numFilas && noTiene; ++i) {
            for (int j = 0; j < numColumnas && noTiene; ++j) {
                menorIgualFila = menorIgualColumna = mayorIgualFila = mayorIgualColumna = true; 
                // Por la izquierda
                for (int a = j; a >= 0 && (mayorIgualFila || menorIgualFila); --a) {
                    if (matriz[i][j] < matriz[i][a]) mayorIgualFila = false;
                    if (matriz[i][j] > matriz[i][a]) menorIgualFila = false;
                }
                // Por la derecha
                for (int a = j; a < numColumnas && (mayorIgualFila || menorIgualFila); ++a) {
                    if (matriz[i][j] < matriz[i][a]) mayorIgualFila = false;
                    if (matriz[i][j] > matriz[i][a]) menorIgualFila = false;
                }
                // Por arriba
                for (int a = i; a < numFilas && (mayorIgualColumna || menorIgualColumna); ++a) {
                    if (matriz[i][j] < matriz[a][j]) mayorIgualColumna = false;
                    if (matriz[i][j] > matriz[a][j]) menorIgualColumna = false;
                }
                // Por abajo
                for (int a = i; a >= 0 && (mayorIgualColumna || menorIgualColumna); --a) {
                    if (matriz[i][j] < matriz[a][j]) mayorIgualColumna = false;
                    if (matriz[i][j] > matriz[a][j]) menorIgualColumna = false;
                }
                noTiene = !((menorIgualFila && mayorIgualColumna) || (mayorIgualFila && menorIgualColumna));
            }
        }

        noTiene ? printf("NO\n") : printf("SI\n");
    }

}