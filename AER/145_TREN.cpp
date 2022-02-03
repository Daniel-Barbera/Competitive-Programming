#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    string entrada;
    vector<char> pila;
    int numParejas;

    /* Pasos:
        1. Leer la entrada
        2. Analizar la entrada elemento a elemento
            - Si el elemento es una mujer, se revisa si el elemento anterior fue el hombre adecuado.
              En caso positivo, se elimina la cumbre.
              En caso contrario, se añade a la pila.
            - Si el elemento es un hombre, se añade a la pila.
            - Si el elemento es un obstáculo, se ignora.
            - Si el elemento es una barrera (@), se despeja la pila.
    */

    while (getline(cin, entrada)) {

        numParejas = 0;

        for (char c: entrada) {
            switch(c) {
                case 'M':
                    if (pila.size() == 0) pila.push_back(c);
                    else {
                        if (pila.back() == 'H') {
                            pila.pop_back();
                            ++numParejas;
                        } else pila.push_back(c);
                    }
                    break;
                case 'm':
                    if (pila.size() == 0) pila.push_back(c);
                    else {
                        if (pila.back() == 'h') {
                            pila.pop_back();
                            ++numParejas;
                        } else pila.push_back(c);
                    }
                    break;
                case '@':
                    pila.clear();
                    break;
                case 'H':
                    pila.push_back(c);
                    break;
                case 'h':
                    pila.push_back(c);
                    break;
                // default: no hacer nada, no es necesario introducir los "obstáculos"
            }
        }

        pila.clear();
        cout << numParejas << endl;
    }

    return 0;
}