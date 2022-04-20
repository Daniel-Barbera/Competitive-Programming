#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

    int numEstados;
    while (scanf("%d", &numEstados) == 1) {
        int numDelegados, numVotantesFavor, numVotantesContra, numIndecisos;
        long long totalDelegadosFavor, totalDelegadosContra, totalIndecisos;

        totalDelegadosFavor = totalDelegadosContra = totalIndecisos = 0L;
        while (numEstados--) {
            scanf("%d %d %d %d", &numDelegados, &numVotantesFavor, &numVotantesContra, &numIndecisos);
            if (numVotantesFavor > numVotantesContra + numIndecisos) totalDelegadosFavor += numDelegados;
            else if (numVotantesFavor + numIndecisos <= numVotantesContra) totalDelegadosContra += numDelegados;
            else {
                  
                totalDelegadosFavor += numDelegados; 
            }
        }
        if (totalDelegadosFavor > totalDelegadosContra) printf("%d\n", totalIndecisos);
        else printf("IMPOSIBLE\n");
    }
    

    return 0; 
}