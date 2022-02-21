#include <bits/stdc++.h>
using namespace std;

    /* Idea para la ventana deslizante:
        - Se mide la distancia entre los dos extremos de la ventana
        - Si el sonido llega más allá de ambos extremos, se añade
        alcanceSonido - distanciaExtremos  al contador, y se desplaza
        el extremo izquierdo (alcanceSonido - distanciaExtremos) unidades.
        - En todas las iteraciones, el extremo derecho de la ventana se reduce en uno.
    */

int main() {
  	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
    int numCasas;
    int musica;
    int musicaOidaPorOtros;
    int izquierda, derecha, alcanceSonido, distanciaExtremos;
    vector<int> casas;
    casas.resize(500005, 0);
    while (cin >> numCasas && numCasas) {
        musicaOidaPorOtros = 0;
        for (int i = 0; i < numCasas; ++i) {
            cin >> casas[i];
        }

        izquierda = derecha = numCasas - 1;
        while (derecha > 0 && izquierda > 0) {
            distanciaExtremos = derecha - izquierda;
            alcanceSonido = casas[derecha];
            if (alcanceSonido > distanciaExtremos) {
                /* hay que tener en cuenta que nunca podemos sumar más que {izquierda} unidades */
                musicaOidaPorOtros += min(alcanceSonido - distanciaExtremos, izquierda);
                izquierda -= alcanceSonido - distanciaExtremos;
            } 
            --derecha;
            if (izquierda > derecha) izquierda = derecha; /* se produce al procesar muchos ceros seguidos */
        }
        cout << musicaOidaPorOtros << '\n';
        casas.clear();
    }
    return 0;
}