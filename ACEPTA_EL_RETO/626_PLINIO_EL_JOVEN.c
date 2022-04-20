#include <stdio.h>

int main() {
    int numCasos, dd, mm, aa;
    scanf("%d", &numCasos);
    while (numCasos--) {
        scanf("%d/%d/%d", &dd, &mm, &aa);
        if (mm < 2 && aa % 4 == 0) printf("29/02/%04d\n", aa);
        else if (mm < 2 && aa % 4 != 0) printf("29/02/%04d\n", (aa/4)*4 + 4);
        else if (mm == 2 && dd < 29 && aa % 4 != 0) printf("29/02/%04d\n", (aa/4)*4 + 4);
        else if (mm == 2 && dd < 29 && aa % 4 == 0) printf("29/02/%04d\n", aa);
        else printf("29/02/%04d\n", (aa/4)*4 + 4);
    }
    return 0; 
}