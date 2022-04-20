#include <bits/stdc++.h>
using namespace std;

int main() {
    string start, end; 
    int numCases;

    cin >> numCases;
    while (numCases--) {
        cin >> start >> end; 
        unordered_map<char, int> s, e;
        for (char c: start) ++s[c];
        for (char c: end) ++e[c];
        for (auto pair: s) {
            char c = pair.first;
            if (e.find(c) == e.end()) {
                start.erase(remove(start.begin(), start.end(), c), start.end());        
            }
        }

        // Es imposible que aparezca la palabra final
        // si cualquiera de sus letras no está en la palabra original,
        // o no aparece tantas veces como en la palabra final.
        bool impossible = false;
        for (char c: end) {
            if (s.find(c) == s.end() || s[c] < e[c]) impossible = true;
            if (impossible) break;
        }

        if (!impossible) { 
            int st = start.find(end.front(), 0);
            start = start.substr(st);
            if (start == end) cout << "YES\n";
            else {
                while (start.length() > end.length()) {
                    auto pair = mismatch(start.begin(), start.end(), end.begin());
                    if (pair.first != start.end()) start.erase(start.find(*pair.first, 0), 1);
                }
                start == end ? cout << "YES\n" : cout << "NO\n";
            }
        } else cout << "NO\n";
    }

    return 0; 
}