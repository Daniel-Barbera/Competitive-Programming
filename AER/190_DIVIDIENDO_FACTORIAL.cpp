#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, den;
    int fact;
    long long int result;
    while(cin >> num >> den && num >= den) {
        fact = num - den;
        result = 1;
        while (fact--) {
            result *= num;
            --num;
        }
        cout << result << '\n';
    }
}