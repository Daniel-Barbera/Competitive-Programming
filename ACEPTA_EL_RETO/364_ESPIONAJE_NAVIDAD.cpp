#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    while (getline(cin, input) && input != "FIN") {
        transform(input.begin(), input.end(), input.begin(), [](char c){
            if (isspace(c)) return c;
            if (c == 'Z') return 'A';
            return ++c;
        });
        cout << input << '\n';
    }
}