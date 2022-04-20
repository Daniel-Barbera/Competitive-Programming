#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool isBalanced(vector<char> &vec, char c);

int main() {
	
	string input;
	set<char> dictionary = {'(', ')', '[', ']', '{', '}'};
	set<char> openers = {'(', '[', '{'};
	
	while (getline(cin, input)) {
	    
		vector<char> vec;
		bool stop = false;
		int i = 0;
		
		// Añadir datos relevantes a vector
		while (!stop && i < input.length()) {
		    // Si el elemento de la cadena es un símbolo válido
			if (dictionary.find(input[i]) != dictionary.end()) {
				// Si es símbolo de apertura, añadir a pila
				if (openers.find(input[i]) != openers.end()) {
					vec.push_back(input[i]);
				}
				// Si es símbolo de cierre, comprobar validez
				// Si no es válido, salir y pasar a la siguiente entrada
				else {
					stop = !isBalanced(vec, input[i]);
				}
			}
			++i;
		}
        if (stop) {
            cout << "NO" << endl;
            continue;
        }
		
		// Si la pila está vacía, la entrada fue válida
		if (vec.empty()) {cout << "YES" << endl;}
		// En caso contrario, no lo fue.
		else {cout << "NO" << endl;}
	}
	
	return 0;
}

bool isBalanced(vector<char> &vec, char c) {
	switch(c) {
		case ')':
			if (vec.empty()) {return false;}	// vector vacío == el primer símbolo es un cierre, salir
			if (vec.back() == '(') {
			    vec.pop_back();
			    return true;
			}
			return false;
		case ']':
			if (vec.empty()) {return false;}
			if (vec.back() == '[') {
			    vec.pop_back();
			    return true;
			}
			return false;
		case '}':
			if (vec.empty()) {return false;}
			if (vec.back() == '{') {
			    vec.pop_back();
			    return true;
			}
			return false;
		default:
			return true;
	}
}


