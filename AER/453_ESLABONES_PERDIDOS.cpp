#include <iostream>
using namespace std;

int main() {
    int numEspecies, numRelaciones;
    int trash;
    while (scanf("%d %d", &numEspecies, &numRelaciones) == 2) {
        for (int i = 0; i < numRelaciones; ++i) scanf("%d %d", &trash, &trash);
        if (numEspecies - numRelaciones != 1) printf("FALTA ALGUNA\n");
        else printf("TODAS\n");
    }
    return 0;
}