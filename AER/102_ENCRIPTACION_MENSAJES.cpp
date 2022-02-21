#include <bits/stdc++.h>
using namespace std;

int modulo(int x,int N){
    return (x % N + N) % N;
}

inline string cesar(string &cad, string &alfabeto, string &otebafla) {
	// Al entrar la cadena en esta función, se garantiza que su longitud es > 1
	// Pasar toda la cadena a minúsculas
    transform(cad.begin(), cad.end(), cad.begin(), [](unsigned char c) {return tolower(c);});
    
    int desplazamiento = 'p' - cad[0];
    int aux;
	// Desde la primera posición cifrable hasta el final de la cadena
    for (int i = 1; i < cad.length(); ++i) {
        if (isalpha(cad[i])) {
            aux = alfabeto.find(cad[i]) + desplazamiento;
            aux = modulo(aux, 26);
            if (desplazamiento >= 0) cad[i] = alfabeto[aux];
            if (desplazamiento < 0) cad[i] = otebafla[aux];
        }
    }

    cad = cad.substr(1);    // Se devuelve la cadena sin el caracter de codificación
    return cad;   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    string otebafla = "zyxwvutsrqponmlkjihgfedcba";
    unordered_set<char> vocales = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int numVocales;
    string input;

    while (getline(cin, input)) {
        numVocales = 0;
        
        // Si la cadena tiene <= caracteres, no hay nada que cifrar
        if (input.length() <= 1) {
            cout << 0 << '\n';
            continue;
        }
        // No se codifica la cadena si el desplazamiento es 0
        if (input[0] != 'p' && input[0] != 'P') input = cesar(input, alfabeto, otebafla);
        // Calcular num. vocales
        for (auto it:input) {
            if (vocales.find(it) != vocales.end()) ++numVocales;
        }
        if (input == "fin") break;
        cout << numVocales << '\n';
    }
    return 0;
}