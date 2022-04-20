#include <set>
#include <iostream>
using namespace std;

int main() {
    set<char> ctoLetras;
    string palabra;
    int numCasos;

    cin >> numCasos;

    for (int j = 0; j < numCasos; ++j) {
        cin >> palabra;
        for (int i = 0; i < palabra.length(); ++i) {
            ctoLetras.insert(palabra[i]);
        }
        if (ctoLetras.count('a') && ctoLetras.count('e') && ctoLetras.count('i') &&
            ctoLetras.count('o') && ctoLetras.count('u')) {
            cout << "SI" << endl;
        }
        else cout << "NO" << endl;
        ctoLetras.clear();
    }

    return 0;
}