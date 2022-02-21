#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string entrada;

    map<string, set<int>> referencias;
    int numCasos;
    int linea;
    while (cin >> numCasos && numCasos) {
        cin.ignore();
        linea = 0;
        while(numCasos--) {
            ++linea;
            getline(cin, entrada);
            istringstream palabras(entrada);
            while (getline(palabras, entrada, ' ')) {
                if (entrada.length() <= 2) continue;
                transform(entrada.begin(), entrada.end(), entrada.begin(), [](unsigned char c) {return tolower(c);});
                if (referencias.find(entrada) != referencias.end()) {
                    referencias.insert(make_pair(entrada, set<int>()));
                }
                referencias[entrada].insert(linea);
            }
        }
        for (auto it: referencias) {
            cout << it.first << ' ';
            auto it2 = it.second.begin();
            for (int i = 0; i < it.second.size() - 1; ++i) {
                cout << *it2 << ' ';
                ++it2;
            }
            cout << *it2 << '\n';
        }
        cout << "----\n";
        referencias.clear();
    }
    return 0;
}