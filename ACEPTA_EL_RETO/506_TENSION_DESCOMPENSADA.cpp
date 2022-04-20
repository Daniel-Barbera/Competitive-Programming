#include <bits/stdc++.h>
using namespace std;

int main() {

    int numCasos, max, min;
    scanf("%d", &numCasos);
    while (numCasos--) {
        scanf("%d / %d", &max, &min);
        max >= min ? printf ("BIEN\n") : printf("MAL\n");
    }


    return 0;
}