#include <iostream>
using namespace std;

int main() {

    int numCasos, numGotas;
    int horas, minutos, segundos;
    string hh, mm, ss;

    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        horas = minutos = segundos = 0;
        cin >> numGotas;

        horas = numGotas / 3600;
        numGotas -= horas*3600;
        minutos = numGotas / 60;
        numGotas -= minutos*60;
        segundos = numGotas;

        if (horas < 10) hh = "0" + to_string(horas);
        else hh = to_string(horas);
        if (minutos < 10) mm = "0" + to_string(minutos);
        else mm = to_string(minutos);
        if (segundos < 10) ss = "0" + to_string(segundos);
        else ss = to_string(segundos);

        printf("%s:%s:%s\n", hh.c_str(), mm.c_str(), ss.c_str());
    }
    return 0;
}