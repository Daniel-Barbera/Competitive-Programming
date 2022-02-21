#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCalcetines = 1;
    int calcetin;
    int maxCalcetines;
    unordered_set<int> mesa;

    while (cin >> numCalcetines && numCalcetines) {
        maxCalcetines = 0;
        while (numCalcetines--) {
            cin >> calcetin;
            if (mesa.find(calcetin) == mesa.end()) mesa.insert(calcetin);
            else mesa.erase(calcetin);
            maxCalcetines = maxCalcetines >= mesa.size() ? maxCalcetines : mesa.size();
        }
        cout << maxCalcetines << '\n';
    }
    return 0;
}