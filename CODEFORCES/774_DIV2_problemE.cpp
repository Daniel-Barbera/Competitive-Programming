#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long int n, m;
    unsigned long long int result;
    scanf("%d %d", &n, &m);
    /* El resultado es:
        # total de celdas en la tabla -> n*m
        A este resultado, hay que restarle los enteros no únicos.
        Éstos se pueden calcular sabiendo que si (a, b) son coprimos,
        en sus filas respectivas no apareceran términos de los otros.
    */
    result = n*m;
    for (int i = 1; i < n; )
}