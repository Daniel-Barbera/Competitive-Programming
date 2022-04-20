#include <iostream>
using namespace std;

int main() {
    int numCasos;
    int pisoInf, pisoSup;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        cin >> pisoInf;
        cin >> pisoSup;
        cout << to_string((pisoInf + pisoSup + 1)*(pisoInf + pisoSup + 2) / 2 - pisoSup) << endl;
    }
    return 0;
}
