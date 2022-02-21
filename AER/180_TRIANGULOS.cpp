#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos;
    int triangulo[3];
    cin >> numCasos;
    
    while (numCasos--) {
        for (int i = 0; i < 3; ++i) {
            cin >> triangulo[i];
        }
        sort(triangulo, triangulo + 3, greater<int>());
        if (triangulo[2] + triangulo[1] <= triangulo[0]) {
            cout << "IMPOSIBLE\n";
            continue;
        }
        if (triangulo[2]*triangulo[2] + triangulo[1]*triangulo[1] == triangulo[0]*triangulo[0]) cout << "RECTANGULO\n";
        else if (triangulo[2]*triangulo[2] + triangulo[1]*triangulo[1] < triangulo[0]*triangulo[0]) cout << "OBTUSANGULO\n";
        else cout << "ACUTANGULO\n";
    }
}