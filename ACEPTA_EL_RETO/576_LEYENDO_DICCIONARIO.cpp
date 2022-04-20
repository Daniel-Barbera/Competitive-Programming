#include <bits/stdc++.h>
using namespace std;

int main() {
    int numSegundos = 1;
    int numDefiniciones;
    int horas, minutos, segundos;
    while (cin >> numSegundos && numSegundos != 0) {
        horas = minutos = segundos = 0;
        while (cin >> numDefiniciones && numDefiniciones != 0) {
            segundos += (numSegundos*numDefiniciones);
        }
        minutos = segundos / 60;
        segundos %= 60;
        horas = minutos / 60;
        minutos %= 60;
        printf("%02d:%02d:%02d\n", horas, minutos, segundos);
    }
}
