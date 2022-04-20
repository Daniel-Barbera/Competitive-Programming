#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string entrada;
    int letras, excl;
    while (getline(cin, entrada)) {
        letras = excl = 0; 
        for (char c: entrada) {
            if (isalpha(c)) ++letras;
            else if (c == '!') ++excl;
        }
        excl > letras ? cout << "ESGRITO\n" : cout << "escrito\n";
    }
    return 0; 
}