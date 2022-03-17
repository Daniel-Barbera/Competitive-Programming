#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCubos, bolita;
    int a, b;
    while (cin >> numCubos >> bolita && numCubos && bolita) {
        while (cin >> a >> b && a && b) {
            if (a == bolita) bolita = b;
            else if (b == bolita) bolita = a;
        }
        cout << bolita << '\n';
    }
}