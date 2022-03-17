#include <bits/stdc++.h>
using namespace std;

int main() {

    int ladoAcera; // <- acera de tamaño l^2
    int x1, x2, y1, y2;
    while (scanf("%d", &ladoAcera) && ladoAcera) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        (x1 + x2 + y1 + y2 % 2) % 2 == 0 ? printf("%d\n", abs(x1 - x2) + abs(y1 - y2)) : printf("IMPOSIBLE\n");
    }
}