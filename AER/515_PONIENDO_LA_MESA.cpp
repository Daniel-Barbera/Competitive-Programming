#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int input;
    while (cin >> input && input) {
        if (input == 1) {cout << input << '\n'; continue;}
        input % 2 == 0 ? cout << input << '\n' : cout << input - 1 << '\n';
    }
    return 0;
}