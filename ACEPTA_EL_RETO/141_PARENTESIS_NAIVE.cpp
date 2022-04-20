#include <iostream>
#include <string>
#include <set>
#include <vector>

// NAIVE: NOT USING A STACK
using namespace std;

bool isBalanced(string str) {
	int pP = str.find("()");
	int pB = str.find("[]");
	int pC = str.find("{}");
	bool notBalanced = false;
	while(!str.empty() && !notBalanced) {
    	while(pP != string::npos) {
    		str.erase(pP, 2);
    		pP=str.find("()");
    	}
    	pB=str.find("[]");
    	while(pB != string::npos) {
    		str.erase(pB, 2);
    		pB=str.find("[]");
    	}
        pC=str.find("{}");
    	while(pC != string::npos) {
    		str.erase(pC, 2);
    		pC=str.find("{}");
    	}	
    	pP = str.find("()");
    	pB = str.find("[]");
	    pC = str.find("{}");
        notBalanced = (pP == pB && pP == pC && !str.empty());
    }
	if (notBalanced) {return false;}
	return true;
}


int main() {
	
	string input;
	set<char> dictionary = {'(', ')', '[', ']', '{', '}'};
	int sP, eP, sB, eB, sC, eC;
	
	while (!cin.eof()) {	
		getline(cin, input);
		vector<char> testCase;
		// Añadir datos relevantes a vector
		for (int i = 0; i < input.length(); ++i) {
			if (dictionary.find(input[i]) != dictionary.end()) {
				testCase.push_back(input[i]);
			}
		}
		// Si el vector está vacío, descartar
		if (testCase.empty()) {
		    cout << "NO" << endl;
		    continue;
		}
		// Descartar si el primer elemento cierra
		if (testCase[0] == ')' || testCase[0] == ']' || testCase[0] == '}') {
			cout << "NO" << endl;
			continue;
		}
		// Al revés, descartar si el final es inválido
		if (testCase[testCase.size()-1] == '(' || 
			testCase[testCase.size()-1] == '{' || 
			testCase[testCase.size()-1] == '[') {
			cout << "NO" << endl;
			continue;
		}
		// Contar cada uno de los elementos
		sP = eP = sB = eB = sC = eC = 0;
		for (int cont = 0; cont < testCase.size(); ++cont) {
			switch(testCase[cont]) {
				case '(':
					++sP;
					break;
				case ')':
					++eP;
					break;
				case '[':
					++sB;
					break;
				case ']':
					++eB;
					break;
				case '{':
					++sC;
					break;
				case '}':
					++eC;
					break;
			}
		}
		// Si hay elementos abiertos, descartar y continuar
		if (!(sP == eP && sB == eB && sC == eC)) {
			cout << "NO" << endl;
			continue;
		}
		// Conversión de vector a string
		string data(testCase.begin(), testCase.end()); 
		// Si se encuentran subcadenas inválidas, descartar
		// Esto es horrible, es O(n^6)
		if (!isBalanced(data)) {cout << "NO" << endl;}
		else {cout << "YES" << endl;}
	}
	return 0;
}
