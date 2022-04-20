#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numFilas;
    int num;
    bool esTriangularSuperior;
    bool esTriangularInferior;
    while (cin >> numFilas && numFilas != 0) {
        esTriangularInferior = esTriangularSuperior = true;
        for (int i = 0; i < numFilas; ++i) {
            for (int j = 0; j < numFilas; ++j) {
                cin >> num;
                if (i == j) continue;
                else {
                    if (i > j && num != 0) esTriangularInferior = false;
                    if (i < j && num != 0) esTriangularSuperior = false;
                }
            }
        }
        if (esTriangularInferior || esTriangularSuperior) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}