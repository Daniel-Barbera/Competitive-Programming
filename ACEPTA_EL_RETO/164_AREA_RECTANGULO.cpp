#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int base, altura;
    pair<int, int> vertInf, vertSup;
    while (cin >> vertInf.first >> vertInf.second >> vertSup.first >> vertSup.second) {
        if (vertSup.first < vertInf.first || vertSup.second < vertInf.second) return 0;
        altura = vertSup.second - vertInf.second;
        base = vertSup.first - vertInf.first;
        cout << base*altura << '\n';
    }
    return 0;
}