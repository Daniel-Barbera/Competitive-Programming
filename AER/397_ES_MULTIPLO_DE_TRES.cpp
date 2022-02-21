#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /* Truco: escribir el resultado para los primeros diez números */
    int numCasos;
    unsigned long long int n;
    cin >> numCasos;
    while (numCasos--) {
        cin >> n;
        (n - 1) % 3 == 0 ? cout << "NO\n" : cout << "SI\n";
    }
    return 0;
}