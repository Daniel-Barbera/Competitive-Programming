#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string entrada;
    unordered_map<char, int> ocurrencias;
    while (getline(cin, entrada)) {
        for (auto it: entrada) {
            if (ocurrencias.find(it) != ocurrencias.end()) ++ocurrencias[it];
            else ocurrencias.insert(make_pair(it, 1));
        }
        auto it = ocurrencias.begin();
        auto aux = it;
        bool isSubnormal = true;
        if (ocurrencias.size() != 10) isSubnormal = false;
        else {
            while (it != ocurrencias.end() && isSubnormal) {
                ++aux;
                if (aux != ocurrencias.end()) 
                    isSubnormal = it->second == aux->second;
                ++it;
            }
        }
        isSubnormal ? cout << "subnormal\n"  : cout << "no subnormal\n"; 
        ocurrencias.clear();
    }
}