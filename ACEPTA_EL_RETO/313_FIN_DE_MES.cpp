#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos, a, b;
    cin >> numCasos;
    while (numCasos--) {
        cin >> a >> b;
        a + b >= 0 ? cout << "SI\n" : cout << "NO\n";
    }
    return 0;
}