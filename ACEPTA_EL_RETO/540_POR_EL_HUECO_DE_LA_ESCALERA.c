#include <stdio.h>

int main() {
    int numCasos, piso, escalonesPiso, pisosSubidos, escalones;
    int result; 
    scanf("%d", &numCasos);
    while (numCasos--) {
        scanf("%d %d %d %d", &piso, &escalonesPiso, &pisosSubidos, &escalones);
        result = pisosSubidos*escalonesPiso+escalones; 
        printf("%d %d\n", result, result + piso*escalonesPiso);
    }
    return 0; 
}