#include <bits/stdc++.h>
using namespace std;

/* Aquí se puede conseguir #1 en AER siendo un dios en C. Me da pereza aprender. */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    cin >> numCasos;
    cin.ignore();
    string entrada;
    while (numCasos--) {
        getline(cin, entrada);
        entrada.erase(entrada.begin(), entrada.begin() + 4);
        cout << "Hola, " << entrada << ".\n";
    }
    return 0;
}