#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int familias[20];
    int numHijos, factor;
    vector<int> hijos;
    int numFamilias = -1;
    while (cin >> numFamilias && numFamilias) {
        for (int i = 0; i < numFamilias; ++i) {
            cin >> numHijos >> factor;
            hijos.resize(numHijos);
            for (int j = 0; j < numHijos; ++j) {
                cin >> hijos[j];
                hijos[j] *= factor;
            }
            familias[i] = *max_element(hijos.begin(), hijos.end());
            hijos.clear();
        }
        sort(familias, familias + numFamilias, greater<int>());
        int i;
        for (i = 0; i < numFamilias - 1; ++i) cout << familias[i] << ' ';
        cout << familias[i] << '\n';
    }
}