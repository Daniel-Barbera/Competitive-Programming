#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) == 2 && (a != 0 || b != 0)) {
        b > a ? printf("SENIL\n") : printf("CUERDO\n");
    }
    
    return 0; 
}