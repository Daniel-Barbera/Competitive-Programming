#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    int numPagina;
    cin >> numCasos;
    while (numCasos--) {
        cin >> numPagina;
        numPagina % 2 != 0 ? cout << numPagina - 1 << '\n' : cout << numPagina + 1 << '\n';
    }
}