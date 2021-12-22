#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool findPokemon(string pokemon, vector<char> &map);

int main() {

    ifstream input;
	input.open("C:/Users/anton/Desktop/SOLUCIONES_CP/CODE_CHALLENGE/2/testInput.txt", ios::in);

    ofstream output;
    output.open("C:/Users/anton/Desktop/SOLUCIONES_CP/CODE_CHALLENGE/2/testOutput.txt", ios::out);

    int numCases, numPokemon, numRows, numColumns, numCells;
    string pokemon;
    string nomekop;
    input >> numCases;

    // Para cada caso
    for (int i = 1; i <= numCases; ++i) {

        input >> numPokemon;
        input >> numRows;
        input >> numColumns;

        // Añadir los pokemon que queremos buscar
        vector<string> pokemonVec;
        for (int j = 0; j < numPokemon; ++j) {
            input >> pokemon;
            nomekop = pokemon;
            reverse(nomekop.begin(), nomekop.end());
            pokemonVec.push_back(pokemon);
            pokemonVec.push_back(nomekop);
        }

        // Crear el "mapa"
        char c;
        vector<char> map;
        numCells = numRows*numColumns*2;
        for(int k = 0; k < numCells; ++k) {
            input >> c;
            if (!(isspace(c))) {
                map.push_back(c);
            }
        }

        int it = 0;
        // Dado que se garantiza que todos los pokemon aparecen en el mapa,
        // buscar cada pokemon hasta haber encontrado todos.
        while (!pokemonVec.empty()) {
            if (findPokemon(pokemonVec[it], map)) {
                // Eliminar cadena original e invertida
                pokemonVec.erase(pokemonVec.begin() + it, pokemonVec.begin() + it + 2);
            }
            else ++it;
            if (it == pokemonVec.size()) {
                it = 0;
            }
        }
        string result (map.begin(), map.end());
        cout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}

bool findPokemon(string pokemon, vector<char> &map) {
    
    // Algoritmo: apilar caracteres mientras coincidan con la cadena buscada.
    // Si los caracteres de la pila resultan en la cadena buscada, eliminar 
    // la cadena del mapa y devolver verdadero.

    bool found = false;
    int start = 0;
    int end = 0;
    int contador = 0;
    int numIterations = map.size() - pokemon.length();

    string stack; // Pseudo-pila
    
    int i = 0;
    int j = 0;
    while(!found && i < numIterations) {
        start = i;
        if (map[i] == pokemon[contador]) {

            stack += map[i];
            ++contador;
            end = i + (pokemon.length());
            j = i;
            found = true;
            while (found && j < (i + pokemon.length())) {
                found = map[j] == pokemon[contador];
                if (found) {
                    stack += map[j];
                    ++contador;
                    ++j;
                }
                else {
                    i += contador;
                    contador = 0;
                }
            }
            if (found) {
                map.erase(map.begin() + start, map.begin() + end);
            }
            start = end = 0;
        }
    }
    if (found) {return true;}
    else {
        string nomekop = pokemon;
        reverse(nomekop.begin(), nomekop.end());
        return findPokemon(nomekop, map); // Si el reverso no está en el mapa, ¿cual es la condición de salida?
        // Posible solución: flag 0/1?
    }
}