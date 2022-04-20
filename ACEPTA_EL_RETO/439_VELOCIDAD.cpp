#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, d, t;
    int numCasos;
    cin >> numCasos;
    string entrada;
    string x, y;
    while (numCasos--) {
        cin >> x >> y;
        v = d = t = 0;
        switch (x[0]) {
            case 'D':
                d = stoi(x.substr(2));
                break;
            case 'T':
                t = stoi(x.substr(2));
                break;
            case 'V':
                v = stoi(x.substr(2));
                break;
        }
        switch (y[0]) {
            case 'D':
                d = stoi(y.substr(2));
                break;
            case 'T':
                t = stoi(y.substr(2));
                break;
            case 'V':
                v = stoi(y.substr(2));
                break;
        }
        if (t && d) printf("V=%d\n",  d / t);
        if (t && v) printf("D=%d\n", t*v);
        if (d && v) printf("T=%d\n",  d / v);
    }
    return 0;
}