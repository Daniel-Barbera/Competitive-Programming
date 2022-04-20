#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    cin >> numCasos;
    cin.ignore();
    string input;
    int horas, minutos;
    while (numCasos--) {
        getline(cin, input);
        sscanf(input.c_str(), "%02d:%02d", &horas, &minutos);
        minutos = 60 - minutos;
        if (minutos == 60) minutos = 0;
        horas = 12 - horas;
        if (minutos != 0) horas--;
        horas = (horas + 12) % 12;
        if (horas == 0) horas = 12;
        printf("%02d:%02d\n", horas, minutos);
    }
    return 0;
}