#include <bits/stdc++.h>
using namespace std;

int main() {

    int numCasos;
    int k; 

    scanf("%d", &numCasos);
    for (int i = 0; i < numCasos; ++i) {
        scanf("%d", &k);
        printf("%d\n", k / 3);
    }
}