#include <iostream>
#include <math.h>
using namespace std;


bool esNumeroKaprekar(int num) {
    long long int cuadrado = pow(num, 2);
    long long int izquierda, derecha;
    long long int modulo = 1;
    izquierda = 1;
    while (izquierda != 0) {
        modulo *= 10;
        derecha = cuadrado % modulo;
        if (derecha == 0) continue;
        izquierda = cuadrado / modulo;
        if (izquierda + derecha == num) return true;
    }
    return false;
}

int main() {
    int num = 1;
    while (scanf("%d", &num) == 1 && num != 0) {
        if (esNumeroKaprekar(num)) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}