#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int numCasos, numPersonas, colados, id, min; 
    scanf("%d", &numCasos);
    while (numCasos--) {
        scanf("%d", &numPersonas);

        vector<int> personas;
        personas.reserve(numPersonas);
        while (numPersonas--) {
            scanf("%d", &id);
            personas.push_back(id);
        }

        min = 1000000; colados = 0; 
        for (int i = personas.size()-1; i >= 0; --i) {
            if (personas[i] > min) ++colados;
            min = std::min(min, personas[i]);
        } 

        printf("%d\n", colados);
    }
    return 0; 
}