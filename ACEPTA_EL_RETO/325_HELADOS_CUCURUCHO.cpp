#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos, numC, numV;
    cin >> numCasos;
    string helado = "";
    string output = "";
    while (numCasos--) {
        cin >> numC >> numV;
        while (numC--) helado += "C";
        while (numV--) helado += "V";
        output += helado + ' ';
        while (next_permutation(helado.begin(), helado.end())) output += helado + ' ';
        output.pop_back();
        cout << output << '\n';
        helado.clear();
        output.clear();
    }
    return 0;
}