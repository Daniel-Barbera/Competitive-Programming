#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_set<string> productos; 
    string entrada;
    int numCasos = 1;
    while (cin >> numCasos && numCasos != 0) {
        cin.ignore();
        for (int i = 0; i < numCasos; ++i) {
            getline(cin, entrada, '\n');
            transform(entrada.begin(), entrada.end(), entrada.begin(), [](unsigned char c){ return tolower(c);});
            productos.insert(entrada);
        }
        cout << productos.size() << "\n";
        productos.clear();
    }
}