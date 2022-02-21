#include <bits/stdc++.h>
using namespace std;

int numDigitosMultiploMin(int num) {
    bool resultado = false;
    unsigned long long int unos = 1;
    while (!resultado) {
        resultado = unos % num == 0;
        if (resultado) return to_string(unos).length();
        unos = unos*10 + 1;
    }
}


int main() {

    int entrada;
    while (scanf("%d", &entrada) == 1) {
        printf("%d\n", numDigitosMultiploMin(entrada));
    }
    return 0;
}