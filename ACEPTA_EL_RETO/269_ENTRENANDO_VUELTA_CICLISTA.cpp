#include <bits/stdc++.h>
using namespace std;

int main() {

    int numCasos, totalRecorridos, kmsAnterior, kms;
    scanf("%d", &numCasos);
    while (numCasos--) {
        totalRecorridos = kmsAnterior = 0;
        while (scanf("%d", &kms) && kms) {
            totalRecorridos += 2*(kms+kmsAnterior);
            kmsAnterior += kms;
        }
        printf("%d\n", totalRecorridos);
    }
    return 0;
}