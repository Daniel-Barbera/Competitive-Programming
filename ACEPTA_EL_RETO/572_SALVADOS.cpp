#include <bits/stdc++.h>
using namespace std;

int main() {

    int numCasos;
    double nota;
    bool suspenso, nueve;
    scanf("%d", &numCasos);
    for (int i = 0; i < numCasos; ++i) {
        suspenso = false;
        nueve = false;
        for (int j = 0; j < 5; ++j) {
            cin >> nota;
            if (nota == 0) suspenso = true;
            if (nota >= 9) nueve = true;
        }
        if (!suspenso || nueve) printf("MEDIA\n");
        else printf("SUSPENSO DIRECTO\n");
    }
    return 0;
}