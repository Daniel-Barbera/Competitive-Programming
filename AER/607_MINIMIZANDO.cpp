#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    unsigned long long int numLineas;
    
    cin >> numCasos;
    while (numCasos--) {
        cin >> numLineas;
        cout << ceil(log2(numLineas)) << '\n';
    }
    return 0;
}