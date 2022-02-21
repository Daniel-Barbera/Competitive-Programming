#include <bits/stdc++.h>
using namespace std;

int main() {
    int numProfes = 1;
    int comienzo, fin;
    while (cin >> numProfes && numProfes != 0) {
        while (numProfes--) {
            cin >> comienzo >> fin;
            for (int i = comienzo; i <= fin; ++i) traducidas[i] = 1;
        }
        cout << traducidas.count() << '\n';
    }
}