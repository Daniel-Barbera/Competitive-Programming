#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

    int numCasos, numIteraciones;
    string num;
    cin >> numCasos;
    cin.ignore();
    unsigned long long int resultado;
    while (numCasos--) {
        cin >> num;
        numIteraciones = 0;
        if (num.length() != 1) {
            resultado = 11;
            while (resultado >= 10) {
                resultado = 1;
                ++numIteraciones;
                for (int i = 0; i < num.length(); ++i) {
                    resultado *= num[i] - '0';
                }
                num = to_string(resultado);
            }
        }
        cout << numIteraciones << '\n';
    }
    return 0;
}