#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    unsigned long long int n;
    cin >> numCasos;
    while (numCasos--) {
        cin >> n;
        cout << n*(n+1)*(n+2)/6 << '\n';
    }
    return 0;
} 