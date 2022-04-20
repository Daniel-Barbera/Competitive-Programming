#include <stdio.h>
#include <string.h>

int main() {
    
    int numCasos;
    scanf("%d\n", &numCasos);
    while (numCasos--) {
        char a[110], b[110];
        gets(a);
        gets(b);
        if (strcmp(a, "Luke") == 0 && strcmp("padre", b) == 0) printf("TOP SECRET\n");
        else printf("%s, yo soy tu %s\n", a, b);
    }
    return 0;
}