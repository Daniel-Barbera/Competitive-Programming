#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int caso = 1;
    while (cin >> caso && caso) {
        caso % 2 != 0 ? cout << "IZQUIERDA\n" : cout << "DERECHA\n";
    }
    return 0;
}