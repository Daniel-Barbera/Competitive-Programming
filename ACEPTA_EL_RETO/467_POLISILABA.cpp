#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int numCasos;
    scanf("%d", &numCasos);
    char x[21], y[21];
    char es[5];
    while (numCasos--) {
        scanf("%s %s %s", x, es, y);
        transform(x, x + 20, x, [](unsigned char c){return tolower(c);});
        transform(y, y + 20, y, [](unsigned char c){return tolower(c);});
        strcmp(x, y) ? printf("NO TAUTOLOGIA\n") : printf("TAUTOLOGIA\n");
    }
    return 0;
}
