#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num = 2;
    string output;
    while (cin >> num && num != 0) {
        if (num == 1) {
            cout << 10 << '\n';
            continue;
        }
        if (num == 2) {
            cout << 9 << '\n';
            continue;
        }
        if (num % 2 != 0) ++num;
        output = "9";
        num /= 2;
        --num;
        while (num != 0) {
            output += "0";
            --num;
        }
        cout << output << '\n';
    }
}

