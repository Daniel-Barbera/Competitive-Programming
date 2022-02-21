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
        a > b ? cout << "PRINCIPIO\n" : cout << "ROMANCE\n";
    }
    return 0;
}