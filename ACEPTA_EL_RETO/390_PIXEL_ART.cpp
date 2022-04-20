#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos;
    cin >> numCasos;
    int m, a, c;
    
    string colores;
    while (numCasos--) {
        cin >> m >> a >> c >> colores;
        for (auto it: colores) {
            switch(it) {
                case 'M':
                    --m;
                    break;
                case 'A':
                    --a;
                    break;
                case 'C':
                    --c;
                    break;
                case 'R':
                    --m; --a;
                    break;
                case 'N':
                    --m;--a;--c;
                    break;
                case 'V':
                    --a; --c;
                    break;
                case 'L':
                    --m; --c;
                    break;
            }
        }
        if (m < 0 || a < 0 || c < 0) cout << "NO\n";
        else cout << "SI " << m << ' ' << a << ' ' << c << '\n';
    }
}