#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, vector<int>> listaAdyacencia;
    int numCalles;
    int numInter;
    int a, b;
    int numVerGradoImpar;

    while (cin >> numCalles && numCalles) {
        cin >> numInter;
        numVerGradoImpar = 0;
        while (numCalles--) {
            cin >> a >> b;
            listaAdyacencia[a].push_back(b);
            listaAdyacencia[b].push_back(a);
        }
        for (auto it: listaAdyacencia) {
            if (it.second.size() % 2 != 0) ++numVerGradoImpar;
        }
        numVerGradoImpar == 2 || numVerGradoImpar == 0 ? cout << "SI\n" : cout << "NO\n";
        listaAdyacencia.clear();
    }

    return 0;
}