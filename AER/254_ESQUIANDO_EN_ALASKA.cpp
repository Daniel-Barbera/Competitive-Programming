#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> esquiadores(200050, 0);
    vector<int> esquis(200050, 0);
    int numPares;
    while (cin >> numPares && numPares) {
        for(int i = 0; i < numPares; ++i) cin >> esquiadores[i];
        for(int i = 0; i < numPares; ++i) cin >> esquis[i];
        sort(esquiadores.begin(), esquiadores.begin() + numPares);
        sort(esquis.begin(), esquis.begin() + numPares);
        int resultado = 0;
        for (int i = 0; i < numPares; ++i) {
            resultado += abs(esquiadores[i] - esquis[i]);
        }
        cout << resultado << '\n';
    }   
}