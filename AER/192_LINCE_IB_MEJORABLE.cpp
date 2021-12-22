#include <iostream>
#include <string>

int minTuneles(std::string secciones) {
    int numTuneles = 0;
    
    // La entrada tiene entre 1 y 3 elementos
	if (std::string.find('.') == std::string::npos) {return 0;}
    if (secciones.length() <= 3) {
        return 1;
    }

    // Más de tres elementos
		// Primeros dos valores
	if (secciones[0] == '.') {
		secciones[1] = 't';
		++numTuneles;
	}
	
    // Donde hay paso, se comprueba si hay túneles adyacentes.
    // Si no lo hay, añade uno a la derecha.
    for (int i = 1; i < (secciones.length() - 1); ++i){
        if (secciones[i] == '.') {
            if (!(secciones[i-1] == 't' or secciones[i+1] == 't')) {
                secciones[i+1] = 't';
                ++numTuneles;
            }
        }
    }
    
    // Ultimo valor
    if (secciones[secciones.length()-1] == '.') {
        if (secciones[secciones.length()-2] != 't') {
            secciones[secciones.length()-2] = 't';
            ++numTuneles;
        }
    }

    return numTuneles;
}

int main() {
    int numCasos;
    std::string caso;
    std::cin >> numCasos;

    for (int i = 1; i <= numCasos; ++i) {
        std::cin >> caso;
        std::cout << minTuneles(caso) << '\n';     
    }

    return 0;
}