#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int numCasos;
    int sumaClave;
    int izquierda, derecha;
    int suma;
    int resultado;
    int aux;
    string input;

    cin >> numCasos;
    while (numCasos--) {
        cin >> sumaClave;
        cin >> input;
        resultado = 0;
        izquierda = derecha = 0;
        suma = 0;

        /* Idea:
            La ventana (entrada[izquierda], ..., entrada[derecha]), comienza vacía
            Se añaden elementos a la ventana desplazando el índice derecho
            Si es necesario quitar elementos (i.e nos hemos pasado o hemos alcanzado el objetivo),
                lo conseguimos desplazando el índice izquierdo hasta que pasemos por debajo del
                objetivo de nuevo, o hasta que la ventana esté vacía (no tiene sentido tener
                un índice izquierdo superior al derecho)
        */

        while (derecha < input.length()) {
            aux = suma + (input[derecha] - '0');
            if (aux > sumaClave) {
                while (aux > sumaClave && izquierda <= derecha) {
                    suma -= (input[izquierda] - '0');
                    aux = suma + (input[derecha] - '0');
                    ++izquierda;
                }
            }
            suma += (input[derecha] - '0');
            if (suma == sumaClave) {
                ++resultado;
                suma -= input[izquierda] - '0';
                ++izquierda;
            }
            ++derecha;
        }
        cout << resultado << "\n";
    }
}
