#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, rango, inicio;
    while(scanf("%d", &a) && a) {
        inicio = a;
        rango = 0;
        while(scanf("%d", &b) && b) {
            if(b == a+1) {
                rango = 1;
            } else {
                if(rango) printf("%d-%d,", inicio, a);
                else printf("%d,", a);
                inicio = b;
                rango = 0;
            }
            a = b;
        }
        if(rango) printf("%d-%d", inicio, a);
        else printf("%d", a);
        printf("\n");
    }
    return 0;
}