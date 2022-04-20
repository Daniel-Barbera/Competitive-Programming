#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string variables[1005];
    string aux;
    unordered_map<string, pair<string, int>> corregidas;
    int numCasos;
    int mayusculas;

    while (cin >> numCasos) {
        cin.ignore();
        for (int i = 0; i < numCasos; ++i) {
            mayusculas = 0;
            getline(cin, variables[i]);
            aux.resize(variables[i].length());
            transform(variables[i].begin(), variables[i].end(), aux.begin(), [&mayusculas](unsigned char c) {
                if (isupper(c)) ++mayusculas;
                return tolower(c);
            });
            if (corregidas.find(aux) == corregidas.end()) {
                corregidas.insert(pair<string, pair<string, int>>(aux, make_pair(variables[i], mayusculas)));
            }
            else if (corregidas.at(aux).second < mayusculas) {
                corregidas.at(aux).first = variables[i];
                corregidas.at(aux).second = mayusculas;
            }
        }
        for (int i = 0; i < numCasos; ++i) {
            aux.resize(variables[i].length());
            transform(variables[i].begin(), variables[i].end(), aux.begin(), [](unsigned char c) {return tolower(c); });
            variables[i] = corregidas[aux].first;
            cout << variables[i] << '\n';
        }
        cout << "---" << '\n';
        corregidas.clear();
    }
    return 0;
}