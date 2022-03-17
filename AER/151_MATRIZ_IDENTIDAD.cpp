#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    int num;
    bool identidad;
    while (scanf("%d", &n) && n) {
        identidad = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &num);
                if (i != j && num != 0 || i == j && num != 1) identidad = false;
            }
        }
        identidad ? printf("SI\n") : printf("NO\n");
    }

}