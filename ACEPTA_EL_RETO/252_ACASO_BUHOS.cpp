#include <bits/stdc++.h>
using namespace std; 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string entrada;
    bool palin;
    while (getline(cin, entrada) && entrada != "XXX") {
        palin = true;
        entrada.erase(remove_if(entrada.begin(), entrada.end(), [](unsigned char c){return isspace(c);}), entrada.end());
        transform(entrada.begin(), entrada.end(), entrada.begin(), [](unsigned char c){return tolower(c);});
        for (int i = 0; i < entrada.length(); ++i) {
            if (entrada[i] != entrada[entrada.length()-1-i]) palin = false;
        }
        if (palin) cout << "SI" << '\n';
        else cout << "NO" << '\n';
    }
}