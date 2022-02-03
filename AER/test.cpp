#include <iostream>
using namespace std;

int main() {
    string palabra;
    int numCasos;
    int numE, numI, numO, numU;
    int numA = numE = numI = numO = numU = 0;
    cin >> numCasos;

    for (int j = 0; j < numCasos; ++j) {
        cin >> palabra;
        for (int i = 0; i < palabra.length(); ++i) {
            switch(palabra[i]) {
                case 'a':
                    ++numA;
                    break;
                case 'e':
                    ++numE;
                    break;
                case 'i':
                    ++numI;
                    break;
                case 'o':
                    ++numO;
                    break;
                case 'u':
                    ++numU;
                    break;
            }
        }
        if (numA && numE && numI && numO && numU) {
            cout << "SI" << endl;
        }
        else cout << "NO" << endl;
        numA = numE = numI = numO = numU = 0;
    }

    return 0;
}