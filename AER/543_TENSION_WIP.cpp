#include <iostream>
#include <array>
using namespace std;

/* IDEA DEL ALGORITMO:
	- Crear un grafo ponderado que contenga la posición de las sombrillas en
	  una cuadrícula 1000x1000
	  
	- Cada nodo ocupado en el grafo contendrá como valor el radio que
	  ocupa la sombrilla.
	
	- Las aristas del grafo contendrán la distancia entre cada nodo.
	
	- Si el radio de una sombrilla iguala o excede su distancia a otra, se añade uno
	  al nivel de tensión.
	  
	- Hay que tener cuidado de no sumar dos veces: al recorrer el grafo desde cada 
	  sombrilla, no debemos tener en cuenta la conexión (sombrilla1, sombrilla2) 
	  respecto de (sombrilla2, sombrilla1).
	  
*/ 


int main() {
	int numCases;
	array<array<int, 1001>, 1001>
	return 0;
}