#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int perla, total;
    map<int, int> perlas;
    vector<int> output;

    while (cin >> perla && perla) {
        output.resize(0);
        perlas.clear();
        total = 0;

        ++perlas[perla];
        ++total;
        while (cin >> perla && perla) {
            ++perlas[perla];
            ++total;
        }

        int numperlaImpares = 0, perlaImpar;
        for (auto it : perlas) {
            if (it.second % 2 != 0) {
                ++numperlaImpares;
                perlaImpar = it.first;
                if (perlaImpar != perlas.rbegin()->first) numperlaImpares = 9999;
            }
            if (numperlaImpares > 1) break;
        }

        if (!(total % 2 != 0 && numperlaImpares == 1)) {
            cout << "NO\n";
            continue;
        }

        for (auto it : perlas) {
            for (int i = 0; i < it.second / 2; ++i) {
                output.push_back(it.first);
            }
        }
        output.push_back(perlaImpar);
        for (int i = (output.size() - 2); i >= 0; --i) {
            output.push_back(output[i]);
        }

        int i;
        for (i = 0; i < output.size() - 1; ++i) {
            cout << output[i] << ' ';
        }
        cout << output[i] << '\n';
    }
    return 0;
}