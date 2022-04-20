#include <bits/stdc++.h>
using namespace std;

int main() {

    int numCases;
    int izq, der, result;
    char op;

    cin >> numCases; 
    for (int i = 0; i < numCases; ++i) {
        cin >> izq;
        cin >> op; 
        cin >> der;
        if (op == '+') {
            result = izq + der;
        }
        else {result = izq - der;}
        cout << result;
        while(true) {
            cin >> op;
            if (op == '.') {break;}
            else 
            {
                cin >> der;
                if (op == '+') {result += der;}
                else {result -= der;}
            }
            cout << ", " << result;
        }
        cout << endl;
    }
    return 0;
}