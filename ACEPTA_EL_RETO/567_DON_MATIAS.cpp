#include <bits/stdc++.h>
using namespace std;

/*
typedef struct Estudiante {
    int notaFiable = -1;
};
*/

typedef struct CuestionarioPareja {
    int id1;
    int id2;
    int nota;
}

int main() {

    int numEstudiantes;
    int numTestFiables;
    int numTestDistancia;
    int notasFiables[4000 + 1];
    
    string cuestionarioFiable;
    ios_base::sync_with_stdio(false);
    while (cin >> numEstudiantes && cin >> numTestFiables && cin >> numTestDistancia && 
          !(numEstudiantes == numTestDistancia == numTestFiables == 0)) { 
        fill(notasFiables, notasFiables + 4001, -1);
        for (int i = 1; i <= numEstudiantes; ++i) {
            int personas;
            int idEstudiante;
            int idEstudiante2;
            int nota;
            cin >> personas;
            if (personas == 1) {
                cin >> idEstudiante;
                cin >> nota;
                notasFiables[idEstudiante] = nota;
            } else {
                cin >> idEstudiante;
                cin >> idEstudiante2;
                cin >> nota;
                if (notasFiables[idEstudiante] != -1) notasFiables[idEstudiante2] = nota -notasFiables[idEstudiante];
                else if (notasFiables[idEstudiante2] != -1) notasFiables[idEstudiante] = nota - notasFiables[idEstudiante2];
            }
        }

    }
    printf("---\n");
    return 0;
}