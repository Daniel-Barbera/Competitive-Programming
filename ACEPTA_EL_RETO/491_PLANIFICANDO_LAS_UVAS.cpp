#include <bits/stdc++.h>
using namespace std;

int threshold, amt;
vector<long long> grapes;


int solve(int wht, int qty, int idx) {
    // Casos base
    if (qty == 12 && wht <= threshold) return 1;
    if (wht > threshold || qty > 12 || idx >= grapes.size()) return 0; 

    // Transición -> ¿Coges la i-ésima uva?
    return solve(wht + grapes[idx], qty + 1, idx + 1) + solve(wht, qty, idx + 1);
}

int main() {

    while (cin >> threshold >> amt && (threshold || amt)) {
        while (amt--) {
            int grp;
            cin >> grp;
            grapes.push_back(grp);
        }
        cout << solve(0, 0, 0) << '\n';
        grapes.clear();
    }
}