#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int alturaPapel, alturaEdificio;
    while (scanf("%lld %lld", &alturaPapel, &alturaEdificio) == 2) {
        int ctr = 0;
        alturaEdificio *= pow(10, 6);

        while (alturaEdificio > alturaPapel) {
            alturaPapel = alturaPapel << 1;
            ++ctr;
        }

        printf("%d\n", ctr);
    }

    return 0;
}
