#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int numCasos;
    int sumaClave, suma;
    int aux, izquierda, derecha, resultado;
    string cadenaDigitos;

    cin >> numCasos;
    while (numCasos--) {
        cin >> sumaClave;
        cin >> cadenaDigitos;
        resultado = izquierda = derecha = suma = 0;

        /* Idea:
            La ventana (entrada[izquierda], ..., entrada[derecha]), comienza vacía
            Se añaden elementos a la ventana desplazando el índice derecho
            Si es necesario quitar elementos (i.e nos hemos pasado o hemos alcanzado el objetivo),
                lo conseguimos desplazando el índice izquierdo hasta que pasemos por debajo del
                objetivo de nuevo, o hasta que la ventana esté vacía (no tiene sentido tener
                un índice izquierdo superior al derecho)
        */

        while (derecha < cadenaDigitos.length()) {
            // Comprueba si al sumar el siguiente dígito nos vamos a pasar
            aux = suma + (cadenaDigitos[derecha] - '0');  
            // Si es así, quitar elementos  
            if (aux > sumaClave) {
                while (aux > sumaClave && izquierda <= derecha) {
                    suma -= (cadenaDigitos[izquierda] - '0');
                    aux = suma + (cadenaDigitos[derecha] - '0');
                    ++izquierda;
                }
            }

            suma += (cadenaDigitos[derecha] - '0');
            if (suma == sumaClave) {
                ++resultado;
                suma -= cadenaDigitos[izquierda] - '0'; // Quitamos un elemento para no pasarnos en la sig. iter.
                ++izquierda;
            }
            ++derecha;
        }
        cout << resultado << "\n";
    }
}
