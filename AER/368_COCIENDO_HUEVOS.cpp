#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    a = b = 1;
    while (cin >> a >> b && a && b) {
        a % b != 0 ? cout << ((a / b)+ 1)*10 << '\n' : cout << (a / b)*10 << '\n';
    }
    
    return 0;
}