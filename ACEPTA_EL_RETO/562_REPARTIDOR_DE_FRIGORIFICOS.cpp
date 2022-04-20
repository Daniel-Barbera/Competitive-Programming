#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int alto, ancho, numRepartos;
    int a, b;
    vector<int> x, y;
    while (cin >> alto >> ancho >> numRepartos && alto) {
        while (numRepartos--) {
            cin >> a >> b;
            x.push_back(a); y.push_back(b);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (x.size() % 2 != 0) a = x[x.size() / 2];
        else a = x[x.size() / 2 - 1];
        if (y.size() % 2 != 0) b = y[y.size() / 2];
        else b = y[y.size() / 2 - 1];

        cout << a << ' ' << b << '\n';
        x.clear(); y.clear();
    }

    return 0;
}