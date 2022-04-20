#include <bits/stdc++.h>
using namespace std;

int main() {

    int numCases = 1;
    int numNames = 0;
    unordered_multiset<string> bolsaNombres;
    string input;
    while (cin >> numCases && numCases != 0) {
        bolsaNombres.erase(bolsaNombres.begin(), bolsaNombres.end());
        for (int i = 0; i < numCases; ++i) {
            cin >> input;
            if (!input.empty()) {bolsaNombres.insert(input);}
        }

        cin >> numNames;
        for (int i = 0; i < numNames; ++i) {
            cin >> input;
            if (!input.empty()) {
                bolsaNombres.insert(input);
                cout << bolsaNombres.count(input) << endl;
                }
        }
        cout << '\n';
    }
    return 0;
}