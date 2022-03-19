#include <bits/stdc++.h>
using namespace std;

int main() {

    int numCases;
    string fWord, sWord, aux; 
    cin >> numCases;
    cin.ignore();

    while (numCases--) {
        cin >> fWord >> sWord;
        transform(fWord.begin(), fWord.end(), fWord.end(), [](char& c){if (c == 'v' || c == 'V') c = 'b'; c = tolower(c); return c;});
        transform(sWord.begin(), sWord.end(), sWord.end(), [](char& c){if (c == 'v' || c == 'V') c = 'b'; c = tolower(c); return c;});
        aux = fWord;
        bool found = false; 
        for (int i = 0; i < aux.length() && !found; ++i) { 
            rotate(aux.begin(), aux.begin()+1, aux.end());
            found = aux == sWord;
        }
        if (fWord != sWord && found) cout << "SI\n";
        else cout << "NO\n";
    }
}