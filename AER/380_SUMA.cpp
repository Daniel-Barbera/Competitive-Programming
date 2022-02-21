#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    int numGastos = 1;
    int aux;
    int suma;
    while (cin >> numGastos && numGastos != 0) {
        suma = 0; 
        while (numGastos--) {
            cin >> aux;
            suma += aux;
        }
        cout << suma << "\n";
    }
}