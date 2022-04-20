#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int base, altura;
    while (cin >> base >> altura) {
        if (base < 0 || altura < 0) return 0;
        cout << base*2 + altura*2 << '\n';
    }
    return 0;
}