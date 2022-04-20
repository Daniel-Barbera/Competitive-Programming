#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        (b + 1) % 10 == (a % 10) && b > a ? printf("FELIZ DECADA NUEVA\n") : printf("TOCA ESPERAR\n");
    }
    return 0; 
}