#include <bits/stdc++.h>
using namespace std;


// Algoritmo: que te den un conjunto de bolos de 'n' filas, diciéndote que se ha 
// tumbado un bolo en la fila 'm', equivale a calcular cuántos bolos se han caido
// en un subconjunto de bolos de m filas habiendo acertado el primer bolo (es decir, 
// se tumban todos los bolos del subconjunto)

// Teniendo eso en cuenta, podemos calcular fácilmente cuantos bolos quedan por tumbar
long long int calcularNumBolos(long long int numFilas);

int main() {
    long long int numFilas, numFilaBolo;
    long long int numFilasSub;
    numFilas = numFilaBolo = 1;
    while (cin >> numFilas && numFilas != 0 && numFilaBolo != 0) {
        cin >> numFilaBolo;
        // De verdad que tiene que haber una forma mejor de calcular el # filas
        numFilasSub = -numFilaBolo + numFilas + 1;                                              
        cout << calcularNumBolos(numFilas) - calcularNumBolos(numFilasSub) << endl;
    }
    return 0;
}

long long int calcularNumBolos(long long int numFilas) {

    // el cálculo se corresponde a la serie a(n) = n(n+1)/2
    // basta con sustituir la n del término general por el número de filas

    return numFilas*(numFilas + 1)/2;
}