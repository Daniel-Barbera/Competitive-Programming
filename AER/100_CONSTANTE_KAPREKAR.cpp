#include <iostream>
#include <algorithm>

using namespace std;


int resta(int numero) {
	
	int digito1, digito2, digito3, digito4;
	int aux1, aux2;
		
	digito1 = numero/1000;
	numero = numero%1000;
	digito2 = numero/100;
	numero = numero%100;
	digito3 = numero/10;
	digito4 = numero%10;
		
	 if (digito1 == digito2 == digito3 == digito4) {
		 return 40404;
	 }
	 else {
		 int digitos[4] = {digito1, digito2, digito3, digito4};
	     sort(digitos, digitos+4);
	     
		 aux1 = (digitos[3]*1000) + (digitos[2]*100) + (digitos[1]*10) + (digitos[0]);
		 aux2 = (digitos[0]*1000) + (digitos[1]*100) + (digitos[2]*10) + (digitos[3]);
		 
		 if (aux1 > aux2) {
			 return (aux1 - aux2);
		 }
		 else {
			 return (aux2 - aux1);
		 }
	 }	
}

int Kaprekar(int numero) {
	int numLlamadas;
	int aux;
		
	if (resta(numero) == 40404) {
		return 8;
	}
		
	if (numero == 6174) {
		return 0;
	}
	else {
		numLlamadas = 0;
		aux = numero;
		while (aux != 6174) {
			aux = resta(aux);
			++numLlamadas;
		}
		return numLlamadas;
	}		
}


int main() {
    
	int entrada, numCasos;
	
	cin >> numCasos;
	for (int i = 1; i < (numCasos + 1); ++i) {
		cin >> entrada;
		cout << Kaprekar(entrada) << '\n';
	}
	
	return 0;  
}
		