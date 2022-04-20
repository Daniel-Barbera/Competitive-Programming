#include <bits/stdc++.h>
using namespace std;

int main() {
    int numCalcetines = 1;
    int calcetin;
    int maxCalcetines;
    unordered_set<int> mesa;

    while (scanf("%d", &numCalcetines) && numCalcetines) {
        maxCalcetines = 0;
        while (numCalcetines--) {
            scanf("%d", &calcetin);
            if (mesa.find(calcetin) == mesa.end()) mesa.insert(calcetin);
            else mesa.erase(calcetin);
            maxCalcetines = maxCalcetines >= mesa.size() ? maxCalcetines : mesa.size();
        }
        printf("%d\n", maxCalcetines);
    }
    return 0;
}