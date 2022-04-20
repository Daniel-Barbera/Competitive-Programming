#include <bits/stdc++.h>
using namespace std;

int main() {
    string num;
    string resultado;
    int suma;
    ios_base::sync_with_stdio(false);
    while (cin >> num && stoi(num, nullptr, 10) >= 0) {
        suma = 0;
        resultado.clear();
        int i;
        if (num.length() == 1) cout << num << " = " << num << "\n";
        else {
            for (i = 0; i < num.length() - 1; ++i) {
                suma += (num[i] - '0');
                resultado += num[i];
                resultado += " + ";
            }
            suma += (num[i] - '0');
            resultado += num[i]; 
            resultado += " = " + to_string(suma);
            cout << resultado << "\n";
        }
    }
    return 0;
}