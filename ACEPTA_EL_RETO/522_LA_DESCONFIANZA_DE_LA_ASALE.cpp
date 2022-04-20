#include <bits/stdc++.h>
using namespace std; 

void weirdSort(string& auxA, vector<double>& palA);

int main() {
    ios_base::sync_with_stdio(false);

    string a, b, auxA, auxB;
    vector<double> palA, palB;

    while (cin >> a >> b) {
        auxA = string(a), auxB = string(b);
        auxA.resize(11, '0');
        auxB.resize(11, '0');
        weirdSort(auxA, palA);
        weirdSort(auxB, palB);

        bool first = true;
        int i = 0, size = 0;
        size = min (palA.size(), palB.size());

        while (first && i < size) {
            if (palA[i] < palB[i]) break;
            if (palB[i] < palA[i]) {
                first = !first;
                break;
            }
            i++;
        }

        first ? cout << a << '\n' : cout << b << '\n';
        palA.clear();
        palB.clear(); 
    }

    return 0;
}

void weirdSort(string& auxA, vector<double>& palA) {
    int i = 0;
    while (i < auxA.size()) {
        if (auxA[i] != 'c' && auxA[i] != 'l') {
            palA.push_back(auxA[i]);
        } else if (i+1 >= auxA.size()) {
            palA.push_back(auxA[i]);
        } else {
            switch(auxA[i]) {
                case 'c':
                    if (auxA[i+1] == 'h') {
                        palA.push_back('c' + 0.5);
                        ++i;
                    } else palA.push_back('c');
                    break;
                case 'l':
                    if (auxA[i+1] == 'l') {
                        palA.push_back('l' + 0.5);
                        ++i;
                        break;
                    } else palA.push_back('l');
                    break;
            }
        }
        ++i;
    }
    return;
} 
