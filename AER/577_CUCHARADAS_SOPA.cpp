#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int numCasos;
    int min, max, real;
    cin >> numCasos;
    while (numCasos--) {
        cin >> min >> max >> real;
        if (min + max < real) {
            real = max + 1;
        } else {
            real = real - min + 1;
        }
        cout << real << "\n";
    }
}