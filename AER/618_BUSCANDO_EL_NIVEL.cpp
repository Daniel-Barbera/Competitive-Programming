#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    array<int, 105> niveles;
    cin.tie(nullptr);

    int numNiveles, interv;
    int start, end, result; 
    while (cin >> numNiveles && numNiveles) {
        for (int i = 1; i <= numNiveles; ++i) {
            cin >> niveles[i];
        }
        cin >> interv;
        while (interv--) {
            result = 0;
            cin >> start >> end;
            if (start < end) {
                for (int i = start + 1; i < end; ++i) {
                    result += niveles[i];
                }
            } else if (start > end) {
                for (int i = start; i >= end; --i) {
                    result -= niveles[i];
                }
            } else result = -niveles[end];
            cout << result << '\n';
        }
        cout << "---\n";
    }

    return 0; 
}
