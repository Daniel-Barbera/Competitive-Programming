#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string entrada;
    int numDigitos = 1;
    while (cin >> numDigitos && numDigitos) {
        while (numDigitos--) {
            entrada += "1";
        }
        cout << entrada << '\n';
        entrada.clear();
     }
    return 0;
}