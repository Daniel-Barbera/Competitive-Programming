#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos;
    cin >> numCasos;
    int numTiras;
    int espumillon[100000];
    int suma;
    while (numCasos--) {
        cin >> numTiras;
        for (int i = 0; i < numTiras; ++i) cin >> espumillon[i];
        sort(espumillon, espumillon + numTiras, greater<int>());
        suma = 0;
        for (int i = 0; i < numTiras - 2 && !suma;  ++i) {
            if ((espumillon[i + 1] + espumillon[i + 2]) > espumillon[i]) 
                suma = (espumillon[i + 2] + espumillon[i + 1] + espumillon[i]);
        }
        suma ? cout << suma << '\n' : cout << "NO HAY NINGUNO\n";
    }
    return 0;
}