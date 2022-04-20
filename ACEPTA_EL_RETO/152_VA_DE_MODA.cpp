#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, int> modas;

    int nums, a;
    while (cin >> nums && nums) {
        for (int i = 0; i < nums; ++i) {
            cin >> a;
            ++modas[a];
        }
        int moda = 0, idx = 0;
        for(auto it: modas) {
            if (it.second > moda) {
                moda = it.second;
                idx = it.first;
            }
        }
        cout << idx << '\n';
        modas.clear();
    }
}