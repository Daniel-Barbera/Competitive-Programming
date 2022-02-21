#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos;
    int a, b;
    cin >> numCasos;
    while (numCasos--) {
        cin >> a >> b;
        a*b % 2 == 0 ? cout << (a*b)/2 << ' ' << (a*b)/2 << '\n' : cout << (a*b)/2 + 1 << ' ' << (a*b) / 2 << '\n';
    }
}