#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    string numero;
    string numero2;

    cin >> numCasos;
    while (numCasos--) {
        cin >> numero;
        sort(numero.begin(), numero.end());
        cin >> numero2;
        sort(numero2.begin(), numero2.end());
        if (numero == numero2) cout << "GANA" << '\n';
        else cout << "PIERDE" << '\n';
    }
}