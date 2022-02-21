#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    int avisos;
    int temperatura;
    bool avisar;
    while (cin >> numCasos && numCasos != 0) {
        avisar = true;
        avisos = 0;
        while (numCasos--) {
            cin >> temperatura;
            if (temperatura <= 4 && avisar) {
                ++avisos;
                avisar = false;
            }
            if (temperatura > 6) avisar = true;
        } 
        cout << avisos << '\n';
    }
    return 0;
}