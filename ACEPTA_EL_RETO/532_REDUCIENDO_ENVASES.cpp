#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos, a, b;
    cin >> numCasos;
    while (numCasos--) {
        cin >> a >> b;
        cout << b - a << '\n';
    }
}