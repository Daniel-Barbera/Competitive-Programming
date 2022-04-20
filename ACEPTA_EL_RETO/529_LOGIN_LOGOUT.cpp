#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos, numI, numO, numParejas;
    string input;
    cin >> numCasos; cin.ignore();
    
    while (numCasos--) {
        numI = numO = numParejas = 0;
        getline(cin, input);
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == 'I') ++numI;
            else ++numO;
        }
        while (numI && numO) {
            --numI;
            --numO;
            ++numParejas;
        }
        cout << numParejas + abs(numI - numO) << '\n';
    }
}